/*
 * file:     mb_comm_sys_p14.c
 * unit:     yes
 * function: func_021F1064, func_021F10D4, func_021F10DC, func_021F10E4, func_021F10EC, func_021F10F4, func_021F10FC, func_021F1104, func_021F110C, func_021F1110, func_021F1118, func_021F1120, func_021F1134, func_021F1148, func_021F115C, func_021F1164
 * address:  0x021F1064
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 b00:1,b01:1,b02:1,b03:1,b04:1,b05:1,b06:1,b07:1;
    u16 b08:1,b09:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1;
} Flags;

typedef struct { u8 pad00[0x18]; Flags f18; u16 f1a; u8 f1c; } State;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags f18;
    Ov107Flags f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx;

void func_021F1064(unsigned char *p);
int func_021F10D4(State *p);
int func_021F10DC(State *p);
int func_021F10E4(State *p);
int func_021F10EC(State *p);
int func_021F10F4(State *p);
int func_021F10FC(State *p);
int func_021F1104(State *p);
int func_021F110C(State *p);
int func_021F1110(Ov107Ctx *p);
unsigned short func_021F1118(Ov107Ctx *p);
unsigned short func_021F1120(Ov107Ctx *p);
int func_021F1134(Ov107Ctx *p);
int func_021F1148(Ov107Ctx *p);
int func_021F115C(Ov107Ctx *p);
int func_021F1164(Ov107Ctx *p);

void func_021F1064(unsigned char *p)
{
    unsigned short *h = (unsigned short *)(p + 0x18);
    *h = *h & ~(unsigned short)2;
    *h = *h & ~(unsigned short)4;
    *h = *h & ~(unsigned short)8;
    *h = *h & ~(unsigned short)0x10;
    *h = *h & ~(unsigned short)0x20;
    *h = *h & ~(unsigned short)0x40;
    *h = *h & ~(unsigned short)0x80;
    *h = *h & ~0x100;
    *h = *h & ~0x200;
    *h = *h & ~0x400;
    *h = *h & ~0x1000;
    p[0x1C] = 0;
}

/*
 * leaf: parent cleared all eight original Thumb starts; 60 bytes stop
 * before existing 021F1110. Both 10DC and10E4 read bit4 in the ROM.
 */
int func_021F10D4(State *p) { return p->f18.b03; }

int func_021F10DC(State *p) { return p->f18.b04; }

int func_021F10E4(State *p) { return p->f18.b04; }

int func_021F10EC(State *p) { return p->f18.b06; }

int func_021F10F4(State *p) { return p->f18.b07; }

int func_021F10FC(State *p) { return p->f18.b08; }

int func_021F1104(State *p) { return p->f18.b10; }

int func_021F110C(State *p) { return p->f1c; }


int func_021F1110(Ov107Ctx *p)
{
    return p->f18.b14;
}


unsigned short func_021F1118(Ov107Ctx *p)
{
    return p->f24;
}


unsigned short func_021F1120(Ov107Ctx *p)
{
    return (p->f24 & 0x3FFF0000) >> 16;
}


int func_021F1134(Ov107Ctx *p)
{
    if (p->f24 & 0x40000000) {
        return 1;
    }
    return 0;
}


int func_021F1148(Ov107Ctx *p)
{
    if (p->f24 & 0x80000000) {
        return 1;
    }
    return 0;
}


int func_021F115C(Ov107Ctx *p)
{
    return p->f18.b15;
}


int func_021F1164(Ov107Ctx *p)
{
    return p->f1A.b00;
}
