/*
 * function: func_021D2FD8
 * address: 0x021D2FD8
 * packet: pkt_ov093_021D2FD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 * symbols:
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021F883C 0x021F883C thumb ov094
 *   d_021EFF80 0x021EFF80 data a2
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021BA2D4 0x021BA2D4 thumb ov093
 *   func_02005F38 0x02005F38 thumb
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_02005D90 0x02005D90 thumb
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021B8E70(u8 *, u32);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern int func_021F7EB4(void);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern void func_021EAF18(u8 *, int, int);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(u8 *, int);
extern void func_021F883C(u32);
extern const u16 d_021EFF80[];
extern int func_021EA710(u32);
extern void func_021BA2D4(void *p, void *m);
extern int func_02005F38(void);
extern void func_021F7C0C(void);
extern void func_02005D90(u32, u32);
extern void func_021B92A0(u32);
extern void func_021EA614(u32, u8 *);
int func_021D2FD8(u32 *a, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7CFC(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (c[2]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((u8 *)a + 0x58, 1, 0x41);
                func_021EAF50((u8 *)a + 0x58, func_021D5440(p));
                func_021F883C(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = d_021EFF80[c[1]];
                else msg = 0x3d;
                func_021EAF18((u8 *)a + 0x58, 1, msg);
            }
            func_021EA614(a[21], (u8 *)a + 0x58);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710(a[21])) {
            if (c[2]) {
                func_021BA2D4((void *)a[0], func_021B98AC((char *const *)a[1], (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!func_02005F38()) {
            func_021F7C0C();
            func_02005D90(0x47c, 0xffff);
            func_021B92A0(a[0]);
            if (c[3]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((u8 *)a + 0x58, 1, 0x42);
                func_021EAF50((u8 *)a + 0x58, func_021D5440(p));
                func_021EA614(a[21], (u8 *)a + 0x58);
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710(a[21])) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}
