/*
 * function: func_021BB854
 * address: 0x021BB854
 * packet: pkt_ov225_021BB854
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04 (lane 09, wave D1): 28 concrete bytes differ, same size (448).
 *   Residue: (1) original compares before `str r7,[r4,#8]` (cmp r0,#0 then store; mine stores first);
 *   (2) stack slots: original countB sp+8, countA sp+0xc, g sp+0x10, rA sp+0x14; mine g sp+8, counts sp+0x10;
 *   declaration order of cb/ca/g did not move them; (3) branch A flag: original `beq; movs 0; b; movs 1`,
 *   mine `bne; movs 1; movs 0` for `(ra == 0) ? 1 : 0` and `ra ? 0 : 1`; branch B matches with `fl = 0; if (rb == 0) fl = 1;`.
 *   Levers found: raw id kept in r6 for BE0/store/BC8 while BD4 result is a second variable; BE0 result in a temp before C98;
 *   locals in function scope; t0 = q->f0->f0 read before the f8 = 1 store.
 * note 2026-10-04 (wD2 lane07): residue (1) fixed by writing `q->f8 = 1;` at the top of each arm (statement repeated per arm, cmp now
 *   precedes the store). Remaining: (2) slot order. With decl `cb, ca, g` slots are g 8, ca 0xc, cb 0x10 (g takes the first slot
 *   whatever its declaration position; ca/cb follow reverse declaration order); original is cb 8, ca 0xc, g 0x10, ra 0x14, so g must
 *   not be the first spilled local. (3) branch A flag `ra == 0 ? 1 : 0`: original `ldr r0,[sp,#0x14]; cmp; beq; movs 0; b; movs 1`,
 *   mine `bne; movs 1; movs 0`. The `fl = 0; if (ra == 0) fl = 1;` form (as in branch B) grows the code (extra movs) and is worse here.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (24 bytes). `int g` (was u16) also gives 24 but adds a
 *   scheduling change at +0x190 (data arg load moves), so the draft keeps u16. Flag in branch A: ternary
 *   `(ra != 0) ? 0 : 1`, `!ra`, if/else into a local (both orders), `fl = 1; if (ra) fl = 0;` all give
 *   `bne; movs 1; b; movs 0` or worse; a store in each arm gives 257 bytes. Swapping the arm order in
 *   source moves the blocks (329). Residue unchanged: slots (cb 8, g 0x10) and the beq/movs 0 flag order.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9C20 0x021B9C20 thumb ov225
 *   func_021B9C34 0x021B9C34 thumb ov225
 *   func_021B9C40 0x021B9C40 thumb ov225
 *   func_021B9BD4 0x021B9BD4 thumb ov225
 *   func_021B9C58 0x021B9C58 thumb ov225
 *   func_021B9BE0 0x021B9BE0 thumb ov225
 *   func_021B9C98 0x021B9C98 thumb ov225
 *   func_021B9BC8 0x021B9BC8 thumb ov225
 *   func_021BA65C 0x021BA65C thumb ov225
 *   func_021BBA70 0x021BBA70 thumb ov225
 *   d_021BC05C 0x021BC05C data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern u16 func_021B9C20(char *);
extern u16 func_021B9C34(char *, int);
extern u16 func_021B9C40(char *, int, int);
extern u16 func_021B9BD4(char *, int);
extern int func_021B9C58(void *, int, void *);
extern u16 func_021B9BE0(char *, int);
extern int func_021B9C98(void *, int, int);
extern u16 func_021B9BC8(char *, int);
extern char *func_021BA65C(char *, char *);
extern void func_021BBA70(void);
extern const char d_021BC05C[];
typedef struct Owner { u32 f0; u16 f4; u16 f6; u16 f8; } Owner;
typedef struct Data { void *f0; u16 f4; char pad6[0x26]; char *f2C; } Data;
typedef struct Q { Owner *f0; Data *f4; u32 f8; u16 fC; char padE[2]; char *f10; u16 f14; u16 f16; char pad18[4]; char *f1C; void *f20; } Q;
Q *func_021BB854(Owner *p, Data *data)
{
    Q *q;
    u32 t, t0;
    u16 cb, ca, g;
    int ra, rb;
    q = func_02030734(data->f4, 0x24, 1, d_021BC05C, 0x61);
    q->f0 = p;
    *(u32 *)((char *)p + 0xC) = 0;
    *(u16 *)((char *)q->f0 + 0x10) = 0;
    q->f4 = data;
    t0 = q->f0->f0;
    if (t0 == 0) {
        q->f8 = 1;
        g = q->f0->f4;
        ca = func_021B9C34(q->f4->f2C, g);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, ca * 8, 1, d_021BC05C, 0x79);
        for (u16 i = 0; i < ca; i++) {
            u16 id;
            int id2;
            id = func_021B9C40(q->f4->f2C, g, i);
            id2 = func_021B9BD4(q->f4->f2C, id);
            if (func_021B9C58(q->f4->f2C, id2, q->f4->f0)) {
                t = func_021B9BE0(q->f4->f2C, id);
                ra = func_021B9C98(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = id;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = func_021B9BC8(q->f4->f2C, id);
                *(u32 *)(q->f10 + q->fC * 8 + 4) = (ra == 0) ? 1 : 0;
                q->fC += 1;
            }
        }
    } else {
        q->f8 = 1;
        cb = func_021B9C20(q->f4->f2C);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, cb * 8, 1, d_021BC05C, 0xB2);
        for (u16 i = 0; i < cb; i++) {
            int id;
            id = func_021B9BD4(q->f4->f2C, i);
            if (func_021B9C58(q->f4->f2C, id, q->f4->f0)) {
                t = func_021B9BE0(q->f4->f2C, i);
                rb = func_021B9C98(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = i;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = func_021B9BC8(q->f4->f2C, i);
                u32 fl = 0;
                if (rb == 0)
                    fl = 1;
                *(u32 *)(q->f10 + q->fC * 8 + 4) = fl;
                q->fC += 1;
            }
        }
    }
    q->f14 = *(u16 *)((char *)q->f0 + 6);
    q->f16 = *(u16 *)((char *)q->f0 + 8);
    q->f1C = func_021BA65C((char *)q + 8, (char *)data);
    q->f20 = func_020056A0((unsigned)func_021BBA70, (unsigned)q, 1);
    return q;
}
