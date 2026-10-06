/*
 * function: func_021BBE5C
 * address: 0x021BBE5C
 * packet: pkt_ov206_021BBE5C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_021BC0AC 0x021BC0AC thumb ov206
 *   func_021BC0E0 0x021BC0E0 thumb ov206
 *   func_020490F4 0x020490F4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   tbl_021BC134 0x021BC134 data
 *   tbl_021BC1C4 0x021BC1C4 data
 *   tbl_021BC184 0x021BC184 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S {
    u16 id;
    char pad2[0xa];
    u16 fc;
    u16 fe;
    char pad10[0x1b8 - 0x10];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S;
extern u32 tbl_021BC134[];
extern u16 tbl_021BC1C4[];
extern u32 tbl_021BC184[];
extern u32 func_020275E4(void);
extern int func_0202D7C8(int a0);
extern u32 func_021BC0AC(void);
extern u32 func_021BC0E0(void);
struct MsgBank;
extern void *func_020490F4(u32 id, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021BBE5C(S *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        switch (i) {
        case 3:
            p->w[i] = func_020490F4(func_020275E4(), p->id);
            break;
        case 4:
            p->w[i] = (void *)func_0202D7C8(p->id);
            break;
        case 5:
            p->w[i] = func_020490F4(func_021BC0AC(), p->id);
            break;
        case 6:
            p->w[i] = func_020490F4(func_021BC0E0(), p->id);
            break;
        default:
            p->w[i] = func_020490F4(tbl_021BC134[i], p->id);
            break;
        }
    }
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] != 0)
                p->objs[i] = p->g[0];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 2:
            if (p->g[1] != 0)
                p->objs[i] = p->g[1];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 3:
            if (p->g[2] != 0)
                p->objs[i] = p->g[2];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        default:
            p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        }
    }
    p->x = func_0201ADE4(p->fc, p->fe, p->id);
    for (i = 0; i < 16; i++)
        p->a[i] = func_02045EC0(p->objs[0], tbl_021BC184[i]);
}
