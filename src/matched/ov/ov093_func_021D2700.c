/*
 * function: func_021D2700
 * address: 0x021D2700
 * packet: pkt_ov093_021D2700
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9C10 0x021B9C10 thumb ov093
 *   func_021EA904 0x021EA904 thumb ov093
 *   func_021EA950 0x021EA950 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F7998(u32 a);
extern int func_021F7EB4(void);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern u8 func_021B8E70(u8 *, u32);
extern char *func_021B9AEC(char *, int);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021EA904(u32 *, u32, u32, u32, u8, u8);
extern int func_021EA950(void *);
int func_021D2700(u32 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021F7998(0x281);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 a = c[0], b = c[1];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950((void *)p[21])) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950((void *)p[21])) return 1;
        break;
    }
    return 0;
}
