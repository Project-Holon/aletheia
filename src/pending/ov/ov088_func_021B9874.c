/*
 * function: func_021B9874
 * address:  0x021B9874
 * packet:   pkt_ov088_021B9874
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct. Blockers: ov088_id/ov168_id (0x58, 0xA8) are overlay ids passed
 * to func_020312F8, which is not in match.py OVERLAY_ID_CONSUMERS; and
 * 0x02184904 (ov009 window, mid-function there, no label in any listing) has no
 * witness outside the range. d_021BD66C/d_021BD974 resolve as sole-ref/data
 * once the ovNNN token is dropped.
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4
 *   ov088_id       0x00000058  data
 *   ov168_id       0x000000A8  data
 */

typedef unsigned int u32;

extern void func_020315D4(int a);
extern void func_020306F0(int a);
extern void func_020312F8(void *a, void *b, int c);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];

int func_021B9874(int a0, int a1, int a2, int *a3)
{
    int t = a3[1];

    func_020315D4(a0);
    func_020306F0(0x16);
    if (t == 0) {
        func_020312F8(ov088_id, d_021BD66C, 0);
    } else if (t == 2) {
        func_020312F8(ov088_id, d_021BD974, 0);
    } else if (t == 3) {
        func_020312F8(ov168_id, d_02184904, 0);
    }
    return 1;
}
