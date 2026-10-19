# A const table load moves above the outgoing stack store; non-const loads stay below

summary: mwcc moves a load from a const object above the outgoing stack-argument store, but not a
load from non-const memory. Declare only the table that feeds the early load const.

Seen in ov170 func_021EE544 (wave D7, closed).

Shape: a call with a stack argument. The original loads one register argument (`ldrb r3,[r3]`)
before `str r1,[sp]`, and the other register arguments after it. The draft put every register
argument load after the store.

Cause: mwcc does not move a load from non-const memory above a store to the outgoing argument
area (it may alias). A load through a `const` object or pointer is free to move above it.

Fix: declare the table that feeds the early load `const` (the extern and the local pointer).
Leave the tables whose loads stay below the store non-const.

```c
extern const unsigned char d_021F0188[];
extern E d_021F0DCC[];
const unsigned char *g = d_021F0188;
...
func_021EEFA4(*(char **)(p + 0x2c), e->a, e->b, g[0], g[1]);
```

Check: if one register-argument load sits above the stack store and the others sit below it,
find which source object is read-only data and make only that one const.
