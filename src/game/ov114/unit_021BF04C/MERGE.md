# unit_021BF04C.c (ov114)

Translation unit 021BF04C..021BF520, 11 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021BF04C.c` is blocked by:

- ov114_func_021BF04C.c..ov114_func_021BF4B0.c: prototype of NHTTPi_GetConnection differs between members (src/matched/ov_sdk/ov114_func_021BF374.c); prototype of NHTTPi_GetConnection differs between members (src/matched/ov_sdk/ov114_func_021BF3E4.
- ov114_func_021BF374.c..ov114_func_021BF4B0.c: prototype of NHTTPi_GetConnection differs between members (src/matched/ov_sdk/ov114_func_021BF3E4.c); prototype of NHTTPi_GetConnection differs between members (src/matched/ov_sdk/ov114_func_021BF444.
- ov114_func_021BF444.c..ov114_func_021BF4B0.c: prototype of NHTTPi_Connection2Response differs between members (src/matched/ov_sdk/ov114_func_021BF4B0.c)

Members, in address order:

- `ov114_func_021BF444.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021BF04C.c` again.
