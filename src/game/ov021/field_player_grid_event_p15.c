/*
 * file:     field_player_grid_event_p15.c
 * unit:     yes
 * function: func_021C06CC, func_021C06E0, func_021C0780
 * address:  0x021C06CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   d_021DA08C  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02164FC4  0x02164FC4  thumb  ov010
 */
struct Desc;
struct BigObj;
struct Ctx;
struct Obj;
struct Evt;
struct IcaAnime;
typedef unsigned int   u32;

typedef unsigned char  u8;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202647C(void *obj);
extern void func_0200FB38(void);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02188C7C(unsigned char *p);
extern int func_02188BE8(void *);
extern void func_0216D9A0(void *);
extern u32 *func_0216D9E4(void *c);
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0200FBA0(void);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02026474(void *obj);
extern u32 func_02026454(void *obj);
extern void func_02164FC4(char *p);
void func_021C06CC(void *p);
int func_021C06E0(u32 a, int *st);
int func_021C0780(u32 a, int *st);
extern u32 d_021DA08C[];
extern char ov021_id[];


/*
 * Spawns the func_021C06E0 task with no work area.
 */
void func_021C06CC(void *p)
{
    func_020122C0(p, 0, func_021C06E0, 0);
}


int func_021C06E0(u32 a, int *st)
{
    void *h = func_020124E4((void *)a);
    void *o = func_0201210C(h);
    void *v;

    switch (*st) {
    case 0:
        func_0216D9A0(func_02188C7C((void *)o));
        if (func_0202647C((void *)func_02012138(h)) == 2) {
            if (func_02012B70(func_020120F4(h)) == 1) {
                func_0200FB38();
                v = func_020146F8(h, (int)o, (int)ov021_id, (int)d_021DA08C, (int)h);
            } else {
                v = func_020122C0(h, 0, func_021C0780, 0);
            }
        } else {
            func_0200FB38();
            v = func_020146F8(h, (int)o, (int)ov021_id, (int)d_021DA08C, (int)h);
        }
        func_02012374((struct Evt *)a, v);
        (*st)++;
        break;
    case 1:
        if (o != 0 && func_02188BE8(o) == 1) {
            func_0216D9E4(func_02188C7C((void *)o));
            return 1;
        }
        break;
    }
    return 0;
}


int func_021C0780(u32 a, int *st)
{
    u32 x;
    u32 y;
    u32 z;

    x = (u32)func_020124E4((struct Obj *)a);
    y = func_02012138((const struct Ctx *)x);
    switch (*st) {
    case 0:
        if (func_0203CD98()) {
            func_0203CEAC(0);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_0203CDBC() == 1) {
            func_0200FBA0();
            func_02012124((struct Ctx *)x, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_020121CC((struct IcaAnime *)x) == 1) {
            *st = *st + 1;
            break;
        }
        return 1;
    case 3:
        z = func_02026474((void *)y);
        if (z && func_02026454((void *)y)) {
            func_02164FC4((char *)z);
            return 1;
        }
        break;
    }
    return 0;
}
