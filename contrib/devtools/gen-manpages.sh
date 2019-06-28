#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CLANCYCOIND=${CLANCYCOIND:-$BINDIR/clancycoind}
CLANCYCOINCLI=${CLANCYCOINCLI:-$BINDIR/clancycoin-cli}
CLANCYCOINTX=${CLANCYCOINTX:-$BINDIR/clancycoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/clancycoin-wallet}
CLANCYCOINQT=${CLANCYCOINQT:-$BINDIR/qt/clancycoin-qt}

[ ! -x $CLANCYCOIND ] && echo "$CLANCYCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($CLANCYCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for clancycoind if --version-string is not set,
# but has different outcomes for clancycoin-qt and clancycoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$CLANCYCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $CLANCYCOIND $CLANCYCOINCLI $CLANCYCOINTX $WALLET_TOOL $CLANCYCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
