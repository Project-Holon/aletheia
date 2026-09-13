# A __FILE__ string whose left neighbour is a table, not a string, cannot be attested

summary: the `string` class fixes a string's start from the terminator of the
string before it, so a file name that happens to be the first thing after a
block of static data has no outside witness at all and its constructor caps at
MATCH however the C is written.

Found in: `src/matched/unit_02008F48.c` (the 0x02008F08 near miss)

`docs/idioms/file-string-is-an-abs32-into-the-string-area.md` says how to write
a `__FILE__` argument, and "The string class" in `docs/MATCHING.md` says why
declaring one is honest: the terminator of the previous string fixes where this
one begins, from bytes outside the compared range. Both assume there *is* a
previous string. Two of this region's file names do not have one.

"mail.c" is at 0x020A716C. What is in front of it is not a string:

```
020A7140  03 02 02 02 02 02 02 02 ... 02 02 00 | m  a  i  l  .  c  00
                                            ^
                                   the only NUL, at 020A716B
```

The single NUL at 0x020A716B satisfies condition 3 of the rule, and condition 4
holds as well. Condition 5 is the one that fails: "the bytes before those NULs
are themselves at least four printable ASCII characters". They are a run of
0x02 and 0x03 bytes, a static table, so the NUL is a zero byte inside data
rather than a string terminator, and the rule refuses. It is right to refuse:
a zero byte in a table says nothing about where a string starts.

The other route, `literal`, needs the address in a second pool word somewhere
in the image, and a `__FILE__` string is passed by exactly one function by
construction. 0x020A716C is named once, by 0x02008F38, which is the word under
test. "wifilist.c" at 0x020A7198 is the same shape: the table in front of it
ends in two NULs and the byte before those is 0x04.

So the whole class of constructors that name a file first in its string section
is closed, and no cut helps, because shrinking the range keeps the one pool
word in it. What the C looks like is not in question; every concrete byte of
0x02008F08 is reproduced. Record the function as a near miss with its source in
the header of a neighbour, note the string it names, and move on. It closes if
anything else in the image ever loads the same address, or if the string area
is ever attested a second way.

The counterpart worth knowing is the good case: "box_savedata.c" at 0x020A706C
sits nine bytes past the terminator of "save_control.c", and widening the
padding window is what let the rule reach it. Padding is not the obstacle here;
a neighbour that is not a string is.
