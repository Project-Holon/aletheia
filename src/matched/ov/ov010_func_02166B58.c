/*
 * function: func_02166B58
 * address:  0x02166B58
 * packet:   pkt_ov010_02166B58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov002 func_021542C0.  The second
 * argument to GAMESYSTEM_CallProc is pooled 0xD7 (215), a linker overlay id for
 * ov215; the third, 0x021F7118, lies in its window.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216559C  0x0216559C  thumb  ov010
 *   ov215_id       0x000000D7  data   a1
 *   d_021F7118     0x021F7118  data   ov215  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32   func_02017E1C(void *obj, u32 key, u32 off);
typedef unsigned char  u8;
struct IcaAnime;
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void  func_0216559C(u16 x);

extern char ov215_id[];
extern char d_021F7118[];

u32 func_02166B58(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];
    u32 a1 = args[1];
    u32 a2 = args[2];

    switch (*mode) {
    case 0:
        if (func_02017E1C((void *)args[3], 0x4C, 0) == 0 || func_02017E1C((void *)args[3], 3, 0) == 1) {
            *mode = 7;
        } else {
            *mode = 1;
        }
        break;
    case 1:
        args[4] = a1;
        args[5] = args[3];
        *mode = 2;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_021BE8D4((void *)a0, a2, 0, 0));
        *mode = 3;
        break;
    case 3:
        func_02012374(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(a0, a2));
        *mode = 4;
        break;
    case 4:
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov215_id, d_021F7118, &args[4]);
        *mode = 5;
        break;
    case 5:
        func_02012374(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        *mode = 6;
        break;
    case 6:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)a0, a2, 0, 0, 1, 0, 0));
        func_0216559C(func_02017E1C((void *)args[3], 5, 0));
        *mode = 7;
        break;
    case 7:
        return 1;
    }
    return 0;
}
