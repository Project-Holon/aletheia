# A later parameter's width reorders the entry spill stores

summary: when the only residue is the order of the parameter spill stores at
function entry (for example `str r2,[sp,#0x10]; str r1,[sp,#0xc]` in the
original against `str r1; str r2` in the build), check the width of the
OTHER spilled parameters, not only of the two that swap. A narrow (u16)
parameter changes where the compiler emits the spill stores of its neighbours.

Found in: `src/matched/ov/ov194_func_021F1E28.c` (wave D7 lane05).

ov194 021F1E28 has params `(u8 *p, int a, u16 b, int c, ...)`; a, b and c are
all spilled at entry. Three earlier lanes changed the types of a and b
(int, u8, u16, short) and the order of the stores in the body: the image's
`b, a, c` order never appeared. Declaring the fourth parameter `u16 c` (it is
only stored to a word field, so the type is not visible elsewhere) gives
`b, a, c` and closes the function (EXACT*).

Measured in ov194 021F3FBC (still open): a u16 or u8 parameter moves its own
spill store to the top of the entry block; u32/int parameters stay in the
middle. Parameter width is a real source fact, so this is not a stand-in.

Mechanism (measured with tools/mwccdbg sched and alias, wave 19): a word
spill of a u8/u16 variable falls in the unknown-memory set G, an int or
pointer spill gets its own exact alias object. Two narrow spills in G alias,
so the earlier one gets a store-store edge (latency 1) to the later one: a
higher height and a larger release count, and the scheduler issues it first.
In 021F1E28 this is b -> c; with c as a pointer, a and b tie and program
order puts a first. `mwccdbg edit --force-alias post:0:2:3` on the pointer
form gives the image order. No source form was found that puts a pointer
spill in G (types of the other parameters, inline helper, address-of,
volatile, K&R definition, opt_* pragmas, scheduling off).
