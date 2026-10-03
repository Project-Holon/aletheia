/*
 * function: func_021E050C
 * address: 0x021E050C
 * packet: pkt_ov183_021E050C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E05C2 alignment padding.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021E07A4 0x021E07A4 thumb ov183
 *   func_021E06D0 0x021E06D0 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 */
typedef unsigned short u16;
struct Data { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };
extern int func_021FC20C(int);
extern int func_021FC214(char *);
extern u16 func_021F9B9C(void *);
extern void *func_0203159C(void *, int, u16);
extern void func_02082BCC(void *, int, unsigned int);
extern void func_021FB964(int, int, u16);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern void *func_021FD760(void *, int, int, u16);
extern void *func_021E07A4(u16, int, void *, int, void *, int *);
struct Source;
extern char *func_021E06D0(const struct Source *src, u16 heap);
extern void *func_0201C440(u16);
extern void *func_021FD12C(int, void *, u16);
extern void func_021FD170(void *, int, int);
int func_021E050C(void *task, int unused, char *q)
{
    struct Data *p;
    int entries[3];
    func_021FC20C(*(int *)(q + 8));
    func_021FC214(*(char **)(q + 8));
    p = func_0203159C(task, 24, func_021F9B9C(*(void **)(q + 12)));
    func_02082BCC(p, 0, 24);
    p->heap = func_021F9B9C(*(void **)(q + 12));
    func_021FB964(*(int *)(q + 8), 29, p->heap);
    func_021FBE54(*(char **)(q + 8), 11, p->heap);
    func_021FBE54(*(char **)(q + 8), 12, p->heap);
    func_021FBE54(*(char **)(q + 8), 6, p->heap);
    p->e = func_021FD760(*(void **)(q + 4), *(int *)(q + 8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, *(void **)(q + 4), *(int *)(q + 8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = func_0201C440(p->heap);
    p->c = func_021FD12C(*(int *)(q + 8), p->d, p->heap);
    func_021FD170(p->c, *(int *)(q + 8), 104);
    return 1;
}
