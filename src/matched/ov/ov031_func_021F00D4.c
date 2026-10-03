/*
 * function: func_021F00D4
 * address:  0x021F00D4
 * packet:   pkt_ov031_021F00D4
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov021
 *   func_021F0680  0x021F0680  thumb  ov031
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021F0584  0x021F0584  thumb  ov031
 *   func_021736C8  0x021736C8  thumb  ov012
 *   func_021F0B98  0x021F0B98  thumb  ov031
 *   func_021F0D64  0x021F0D64  thumb  ov031
 *   func_021F0FE0  0x021F0FE0  thumb  ov031
 *   func_021F0C34  0x021F0C34  thumb  ov031
 *   func_021F0DB0  0x021F0DB0  thumb  ov031
 *   func_021F0EF4  0x021F0EF4  thumb  ov031
 *   func_02173934  0x02173934  thumb  ov012
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02012138(void *p);
extern u8 *func_02026474(void *p);
extern u32 func_02026454(void *obj);
extern void func_021BBA70(u8 *q, int a, u8 *b, int c);
extern void func_021F0680(char *p, u8 *b);
extern void func_0204B3DC(int, int);
extern int func_021F0584(char *p, u8 *flag);
extern void func_021736C8(u8 *a, int v);
extern int func_021F0B98(char *o);
extern int func_021F0D64(char *p);
extern void func_021F0FE0(char *p, u8 *q);
extern void func_021F0C34(u8 *q, char *p);
extern int func_021F0DB0(u8 *a0, char *a1, u8 *a2);
extern void func_021F0EF4(char *p, u8 *q);
extern void func_02173934(u8 *p, int v);

void func_021F00D4(char *p, int mode)
{
    void *s;
    u8 *q;
    u8 *r;
    int res;

    s = func_02012138(*(void **)p);
    q = func_02026474(s);
    if (q != 0) {
        r = q + 0x2830;
        if (r[0xe] == 1) {
            func_021BBA70(q, 0, r + 4, r[0xf]);
            r[0xe] = 0;
        }
        func_021F0680(p, q + 0x30E0);
        if (*(int *)(q + 0x351C) >= 3)
            func_0204B3DC(*(int *)(p + 0x2C), 1);
    }
    if (mode == 1) {
        res = func_021F0584(p, q);
        if (q != 0 && res == 1) {
            switch (*(u8 *)(p + 0x30)) {
            case 0:
                break;
            case 1:
                func_021736C8(q, 2);
                break;
            case 2:
                func_021736C8(q, 3);
                break;
            case 3:
                break;
            case 4:
                func_021736C8(q, 4);
                break;
            case 5:
                func_021736C8(q, 5);
                break;
            }
        }
        *(u8 *)(p + 0x31) = func_021F0B98(p);
        if (*(u8 *)(p + 0x31) == 0)
            *(u8 *)(p + 0x31) = func_021F0D64(p);
        if (*(u8 *)(p + 0x31) == 0 && q != 0)
            func_021F0FE0(p, q);
    }
    if (q != 0) {
        func_021F0C34(q, p);
        if (mode == 1)
            func_021F0DB0(q, p, q + 0x30E0);
        func_021F0EF4(p, q + 0x30E0);
    }
    if (func_02026454(s) == 3 && q != 0)
        func_02173934(q, *(u8 *)(p + 0x30));
}
