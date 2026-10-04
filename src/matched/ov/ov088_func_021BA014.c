/*
 * function: func_021BA014
 * address:  0x021BA014
 * packet:   pkt_ov088_021BA014
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
 *   func_020274C8  0x020274C8  thumb
 *   func_021BC114  0x021BC114  thumb  ov088
 *   func_021BC0FC  0x021BC0FC  thumb  ov088
 *   func_021BC0E4  0x021BC0E4  thumb  ov088
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_02184904     0x02184904  data  ov168  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov168_id       0x000000A8  data
 *   ov107_id       0x0000006B  data
 *   ov088_id       0x00000058  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_020274C8(void);
extern void func_021BC114(void);
extern void func_021BC0FC(void);
extern void func_021BC0E4(void);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_020312F8(int id, void *tmpl, void *arg);
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_02184904[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov168_id[];
extern char ov107_id[];
extern char ov088_id[];

int func_021BA014(int a0, int a1, int a2, char *a3)
{
    u8 sel = *(u8 *)(a3 + 0x129);
    u8 flag = *(u8 *)(a3 + 0x12c);
    char *w;

    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0xb);
    switch (sel) {
    case 0:
        func_020274C8();
        if (flag == 0)
            func_021BC114();
        else
            func_021BC0FC();
        break;
    case 1:
        func_020274C8();
        func_021BC0E4();
        break;
    case 2:
        func_020312F8((int)ov121_id, d_021DF538, 0);
        break;
    case 3:
        w = func_02030734(1, 0x14, 0, d_021BDA00, 0x200);
        func_02082BCC(w, 0, 0x14);
        *(u32 *)(w + 8) = 0;
        *(u32 *)(w + 0x10) = 1;
        func_020312F8((int)ov199_id, d_02213C4C, w);
        break;
    case 4:
        func_020312F8(-1, d_0209DEF0, 0);
        break;
    case 5:
        func_020312F8((int)ov016_id, d_021D77AC, 0);
        break;
    case 6:
        func_020312F8((int)ov168_id, d_02184904, 0);
        break;
    case 7:
        w = func_02030734(1, 8, 1, d_021BDA00, 0x216);
        *(u8 *)w = 1;
        func_020312F8((int)ov107_id, d_021F6D78, w);
        break;
    default:
        func_020312F8((int)ov088_id, d_021BD574, 0);
        break;
    }
    return 1;
}
