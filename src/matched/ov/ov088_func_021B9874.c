/*
 * function: STARTMENU_TitleDemoExit
 * address:  0x021B9874
 * packet:   pkt_ov088_021B9874
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 */

typedef unsigned int u32;

struct S020315D4;
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];

int STARTMENU_TitleDemoExit(int a0, int a1, int a2, int *a3)
{
    int t = a3[1];

    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x16);
    if (t == 0) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD66C, 0);
    } else if (t == 2) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD974, 0);
    } else if (t == 3) {
        PROCSYS_ReplaceGlobal((u32)ov168_id, (u32)d_02184904, 0);
    }
    return 1;
}
