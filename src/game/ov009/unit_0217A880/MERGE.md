# unit_0217A880.c (ov009)

Translation unit 0217A880..0217B828, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0217A880.c` is blocked by:

- ov009_func_0217A880.c..ov009_func_0217B7E8.c: global g_021ACE5C declared two ways (src/matched/ov_sdk/ov009_func_0217A950.c); global g_021ACE5C declared two ways (src/matched/ov_sdk/ov009_func_0217AA20.c); global g_021ACE5C declared two ways (src
- ov009_func_0217A880.c..ov009_func_0217AAA0.c: global g_021ACE5C declared two ways (src/matched/ov_sdk/ov009_func_0217A950.c); global g_021ACE5C declared two ways (src/matched/ov_sdk/ov009_func_0217AA20.c); global g_021ACE5C declared two ways (src
- ov009_func_0217A880.c..ov009_func_0217A950.c: global g_021ACE5C declared two ways (src/matched/ov_sdk/ov009_func_0217A950.c)
- ov009_func_0217AADC.c..ov009_func_0217B7E8.c: type typedef alloc_0217AB78 differs between members (src/matched/ov_sdk/ov009_func_0217AB78.c); type typedef alloc_0217AB78 differs between members (src/matched/ov_sdk/ov009_func_0217AB78.c); global g
- ov009_func_0217AB78.c..ov009_func_0217B7E8.c: type typedef alloc_0217AB78 differs between members (src/matched/ov_sdk/ov009_func_0217AB78.c); type typedef alloc_0217AB78 differs between members (src/matched/ov_sdk/ov009_func_0217AB78.c)

Members, in address order:

- `ov009_func_0217A880.c`
- `ov009_func_0217A950.c`
- `ov009_func_0217AB78.c`
- `ov009_func_0217B7E8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0217A880.c` again.
