/*
 * function: func_02156344
 * address:  0x02156344
 * packet:   pkt_ov009_02156344
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker: byte-correct; two code witnesses remain unresolved. Existing
 *   unit src/matched/ov/ov009_func_021562EC.c contains 0215631C and02156330,
 *   but its function: header lists only021562EC, so its shard cannot attest
 *   0215631C. Owner correction: one comma-separated function: value listing
 *   func_021562EC, func_0215631C, func_02156330, then verify that unit shard.
 *   021AF18C (ov013) is an unlabelled setter; no leaf filed while the existing
 *   unit metadata blocker remains. No ARM9 blocker.
 *   The old note had the switch mapping wrong: 0,1,5,default -> 4; 2 -> 1;
 *   3 -> 2; 4 -> 3, and case 5 needs its own arm (the table's lone `b`).
 *
 * 2026-10-04 (wave D2 lane 04): unit header of ov009_func_021562EC.c corrected to list
 * func_021562EC, func_0215631C, func_02156330 (shard needs regen by the integrator).
 * The remaining blocker is 0x021AF18C in ov013 (pengy's overlay, not touched).
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL func_021AF18C (ov013, pengy's overlay,
 * unlabelled Thumb setter `ldr r1,=A; ldr r2,[r1]; ldr r1,=B; str r0,[r2,r1]; bx lr`, mis-listed as ARM by show). Not filed here.
 *
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: THM_CALL func_021AF18C (ov013,
 *   pengy's overlay, no witness). Not a same-overlay leaf, so no witness filed.
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0215631C  0x0215631C  thumb  ov009
 *   func_021AEF6C  0x021AEF6C  thumb  ov013
 *   func_021AF18C  0x021AF18C  thumb  ov013
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_0215631C(void);
extern void func_021AEF6C(void *, int, int);
extern void func_021AF18C(void (*cb)(void));

void func_02156344(void *a)
{
    u32 v;
    *(u16 *)(g_021A8264 + 0x794) = 1;
    *(u32 *)(g_021A8264 + 0x790) = 1;
    *(u16 *)(g_021A8264 + 0x796) = 1;
    if (*(u32 *)(g_021A8264 + 0x76c) == 0) {
        v = 1;
        switch (*(u32 *)(g_021A8264 + 0x77c)) {
        case 2:
            v = 1;
            break;
        case 3:
            v = 2;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 4;
            break;
        default:
            v = 4;
            break;
        }
        func_021AEF6C(a, v, 1);
        func_021AF18C(func_0215631C);
        *(u32 *)(g_021A8264 + 0x76c) = 1;
    }
}
