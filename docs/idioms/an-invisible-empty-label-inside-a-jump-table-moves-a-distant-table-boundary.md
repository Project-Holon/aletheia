# An invisible empty label inside a jump table moves a distant table boundary

summary: in a large sparse switch, 1.1p1 groups the case list into jump tables
and compare nodes from the total label count.  One extra empty label whose
value falls inside an existing table (its entry is the `break`, so nothing in
the image shows it) changes the grouping at the other end of the switch.

Found in: src/pending/ov/ov021_func_021CA5C4.c (0x021CA5C4, 137 labels).

The image's tree has a 0..113 table at the bottom, compare nodes for 300..359,
and a 400..416 table at the top, reached after explicit compares for 358 and
359.  Writing exactly the labels the image dispatches to (every table entry that
is not the break, every compare node) gives the same tree everywhere except the
top: 1.1p1 folds 359 into a 359..416 table (`adds r0, #0x1e` base) and moves
358 to its own node.

Adding one empty label whose value lies inside the 0..113 table (9, 10, 46..99
or 102, all measured to give the same bytes) reproduces the image tree exactly:
the table entry for that value was already the break, so the bottom is
unchanged, but the label count shifts the top grouping.  Two extra labels (for
example 9 and 10) break it again, and so does any label outside a table (318,
327), which adds a compare node.

How to find it: compile a stub switch with the image's case list and one
distinct call per case (`case N: hN(); break;`), compare only the tree's
constants (`cmp`/`adds`/`subs` immediates and pool literals), then try one
extra label at a time from each table's break entries.  The stub compiles in a
second, so the search over candidate values is cheap and needs no permuter.
