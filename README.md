# Language: C++
# Input: TXT
# Output: TXT
# Tested with: PluMA 1.0, GCC 4.8.4

PluMA plugin to run cluster and classify sequences using SortMerna (Kopylova et al, 2012).

The plugin takes as input a TXT file of keyword-value pairs, tab-delimited:
reads: Sequence data
database: Reference database to use

Classifications will be output in the file aligned_otus.txt.

The plugin relies on sortmerna being in your system PATH.
