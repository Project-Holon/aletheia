/*
 * function: func_02157B88
 * address:  0x02157B88
 * packet:   pkt_ov010_02157B88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02157960  0x02157960  thumb
 *   func_02157AF0  0x02157AF0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { int a; u16 b; } Loc;

extern int func_020399A8();
extern int func_0203D3A8();
extern int func_0203F1FC();
extern void func_02039C68();
extern void func_02157960();
extern void func_02157AF0();

void func_02157B88(int *p)
{
    u8 *b = (u8 *)p;
    if (b[0x676] == 1) {
        Loc l;
        int *s = *(int **)(b + 0x664);
        l.b = func_0203F1FC(s[1], s[0]);
        l.a = *(int *)(b + 0x668);
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 1), 8, &l) == 0)
            return;
        func_02039C68(func_020399A8(), 0x18, (u8)p[0]);
        *(u16 *)(b + 0x670) = 0;
        func_02157960(p, (void *)func_02157AF0, 0x152);
        return;
    }
    *(int *)(b + 0x66C) = 1;
    if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 3), 4, b + 0x66C) == 0)
        return;
    func_02039C68(func_020399A8(), 0x18, (u8)p[0]);
    *(u16 *)(b + 0x670) = 0;
    func_02157960(p, (void *)func_02157AF0, 0x162);
}
