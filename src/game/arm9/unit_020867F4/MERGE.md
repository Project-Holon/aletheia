# unit_020867F4 (arm9)

Parts _p01.._p03 verify EXACT. Blockers (lane 20):
- p01/p02: func_020867F4 declared as (struct Cell *, struct Cell *) in one part and (struct Node *, struct Node *) in the other: pick one pointer type and cast inside bodies;
- p02/p03: struct HeapDesc defined twice with different bodies, plus a void / function-call type clash in the second.
