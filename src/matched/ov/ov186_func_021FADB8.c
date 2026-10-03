/*
 * function: func_021FADB8
 * address: 0x021FADB8
 * packet: pkt_ov186_021FADB8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   memset 0x02082BCC arm
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB594 0x021FB594 thumb ov186
 *   func_021FB5B8 0x021FB5B8 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB3BC 0x021FB3BC thumb ov186
 */
typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;
typedef struct Config { int words[3]; } Config;
extern void *memset(void *, int, unsigned);
extern void func_021FB548(char *p, short *x, short *y);
extern int func_021FB594(char *p);
extern unsigned func_021FB5B8(char *p);
extern void func_021FB494(char *p);
extern int func_021FB7B0(void *, int);
extern void func_021FC124(void *, unsigned, void *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void *func_021FB3BC(void *, void *, int, int, int, int, int, void *, unsigned short);
void func_021FADB8(char *ctx, int mode)
{
    Config config;
    Placement placement;
    short x, y;
    int priority;
    int attr;
    int shift;
    unsigned resource;
    if (*(int *)(ctx + 4) == mode) return;
    *(int *)(ctx + 4) = mode;
    func_021FB548(*(void **)(ctx + 8), &x, &y);
    priority = func_021FB594(*(void **)(ctx + 8));
    attr = func_021FB5B8(*(void **)(ctx + 8));
    func_021FB494(*(void **)(ctx + 8));
    *(int *)(ctx + 0x2c) = 0;
    shift = mode == 0 ? 512 : -512;
    memset(&placement, 0, sizeof(placement));
    placement.x = x;
    placement.y = y + shift;
    placement.animation = func_021FB7B0(*(void **)(ctx + 0xc), 4);
    placement.priority = priority;
    placement.attr = attr;
    func_021FC124(*(void **)(ctx + 0x30), *(int *)(ctx + 0x28) + mode, &config);
    resource = func_021FC20C(*(void **)(ctx + 0x30));
    func_021FC214(*(char **)(ctx + 0x30));
    func_021FB7B0(*(void **)(ctx + 0xc), 3);
    *(void **)(ctx + 8) = func_021FB3BC(&placement, *(void **)(ctx + 0x40), 160, mode, *(int *)(ctx + 0x38), *(int *)(ctx + 0x3c), resource, &config, *(unsigned short *)(ctx + 0x34));
}
