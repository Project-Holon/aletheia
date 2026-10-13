/*
 * function: func_02206EB4
 * address: 0x02206EB4
 * packet: pkt_ov094_02206EB4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: int mode, i, found puts the scan index in r0 and found in r1; mode, found, i differed at seven bytes.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_02208D50 0x02208D50 thumb ov094
 *   func_02207F6C 0x02207F6C thumb ov094
 *   func_022082FC 0x022082FC thumb ov094
 *   func_02207E1C 0x02207E1C thumb ov094
 *   func_020061E4 0x020061E4 thumb
 *   func_02207EF0 0x02207EF0 thumb ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   func_022086F8 0x022086F8 thumb ov094
 *   func_022087C4 0x022087C4 thumb ov094
 *   func_0204B3DC 0x0204B3DC arm
 *   func_022089D4 0x022089D4 thumb ov094
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Obj Obj;
typedef struct {
    char pad[0xc];
    Obj *h;
    char pad10[0x38];
    int a, b, f90;
    char pad54[0x1c];
    u32 b0:1, b1:1, b2:1, b3:1, lo:4, count:8, mid:4, b20:1, flash:5, b26:1, b27:1, b28:1, b29:1, hi:2;
    char pad74[0xc];
} Row;
typedef struct W {
    char pad[0x40];
    Row rows[8];
    struct { u32 lo:4, b4:1, mid:16, b21:1, b22:1, hi:9; } flags;
} W;
typedef struct O O;
extern u32 func_020362DC(void);
extern int func_021F8710(void);
extern void func_02208D50(W *, int, int);
typedef unsigned char  u8;
extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(struct O *o, int idx, int k);
extern void func_02207E1C(struct O *obj, int idx);
extern void func_020061E4(u32 a);
extern void func_02207EF0(struct O *obj, int idx);
extern void GFL_USE_StopAllSe(void);
extern void func_022086F8(O *, int);
extern void func_022087C4(char *, int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_022089D4(W *);
void func_02206EB4(W *p)
{
    int mode, i, found;
    func_020362DC();
    if (p->flags.b22) {
        mode = func_021F8710();
        p->flags.b22 = 0;
        if (mode != 0 && mode != 1) {
            found = 0;
            for (i = 0; i < 8; i++) {
                if (p->rows[i].b0) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                p->flags.b4 ^= 1;
                for (i = 0; i < 8; i++) {
                    if (!(i & 1) && p->rows[i].b29 == 1 && p->rows[i].b3) {
                        func_02208D50(p, i, 1);
                        func_02207F6C(p->rows[i].b, p->rows[i].a, 0, &p->rows[i].f90, 6, 1);
                        func_022082FC((O *)p, i, 0);
                    }
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (p->rows[i].b0)
            func_02207E1C((O *)p, i);
        if (p->rows[i].b1) {
            if (p->rows[i].count == 0)
                func_020061E4(0x56d);
            func_02207EF0((O *)p, i);
        }
        if (p->rows[i].b28) {
            if (p->rows[i].count < 16)
                p->rows[i].count++;
            if (!p->rows[i].b1 && p->rows[i].count == 16) {
                GFL_USE_StopAllSe();
                p->rows[i].count++;
                p->rows[i].b28 = 0;
            }
        }
        if (p->rows[i].b2)
            func_022086F8((O *)p, i);
        if (p->rows[i].b20)
            func_022087C4((char *)p, i);
        if (p->rows[i].h != 0 && p->rows[i].b26) {
            if (p->rows[i].flash == 0 || !p->rows[i].b3 || !p->rows[i].b29) {
                func_0204B3DC(p->rows[i].h, 0);
                p->rows[i].b26 = 0;
            } else {
                func_0204B3DC(p->rows[i].h, p->rows[i].flash & 1);
                p->rows[i].flash--;
            }
            if (p->flags.b4 && !(i & 1))
                func_0204B3DC(p->rows[i].h, 0);
        }
    }
    if (!p->flags.b21)
        func_022089D4(p);
}
