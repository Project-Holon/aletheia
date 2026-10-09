# field_effect (ov021)

19 parts, every one EXACT (was 25). Open boundaries (adjacent parts, checked in round 3):
- p01|p02, p02|p03, p10|p11, p18|p19: c99=DIFF with no compile error (shared strings or inlining).
- p03|p04: struct Obj_021A8E78 is defined twice with different members.
- p04|p05, p17|p18: DIFF.
- p05|p06, p11|p12: func_02082BCC and func_021ABB54/78 take u32 in one part, void * or a struct pointer in the other.
- p06|p07: typedef struct Entry redefined. p13|p14, p16|p17: typedef D redefined. p15|p16: typedef T redefined.
- p07|p08, p08|p09: T_021AAABC / Sub views of one object through u32 and struct pointers.
- p09|p10: func_02082BCC declared (void *, int, int) against four u32.
- p12|p13: func_021ABD08 returns void in one part and int in the other.
- p14|p15: struct T member fn missing in one view.
Each needs one canonical struct per object (Entry, D, T, Obj_021A8E78).