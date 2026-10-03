/*
 * function: func_021CA47C
 * address: 0x021CA47C
 * packet: pkt_ov093_021CA47C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D6C50 0x021D6C50 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C7B7C 0x021C7B7C thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cmd { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };
extern u8 *func_021B9934(char *p, int i);
extern int func_021D6C24(void *);
extern int func_021D5C30(void *);
extern int func_021D59B4(u8 *p, int k);
struct Unk021D6C50;
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern u8 func_021D5440(u8 *p);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021E0434(u8 *);
extern void func_021D8510(void *p);
extern void *func_021D8484(void *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C99A0(void *, const void *);
extern void func_021C5A34(u8 *p, u8 *a);
extern u32 func_021CC8D8(void *, int);
extern void func_021C7B7C(u8 *p, unsigned int i);
extern void func_021CC95C(void *, u32, int);
int func_021CA47C(u8 *p, struct Cmd *q)
{
    u8 *a = func_021B9934(*(char **)(p + 8), (u8)q->id);
    u8 *b = func_021B9934(*(char **)(p + 8), (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!func_021D6C24(a) && !func_021D6C24(b) && !func_021D5C30(a)) {
        k = func_021D59B4(a, 16);
        if (func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = func_021D5440(a);
            y = func_021D5440(b);
            if (q->flag) func_021C5A1C(p, a);
            func_021E0434(a);
            func_021D8510(a);
            func_021D8484(a);
            func_021CD4B0(*(void **)(p + 12), 0x53, x, y);
            func_021C99A0(p, (u8 *)q + 8);
            if (q->flag) func_021C5A34(p, a);
            if (k != func_021D59B4(a, 17)) {
                lock = func_021CC8D8(p + 0x1d74, 0x3f0a);
                func_021C7B7C(p, x);
                func_021CC95C(p + 0x1d74, lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}
