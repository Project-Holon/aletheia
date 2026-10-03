/*
 * function: func_0217DEDC
 * address: 0x0217DEDC
 * packet: pkt_ov176_0217DEDC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * E88B0 returns its allocated record; original call truncates four coordinates to bytes.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021E88B0 0x021E88B0 thumb ov177
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {
    u32 f00, f04, f08, option0, option1, f14, f18, count;
    u16 f20, f22, f24, f26;
    u32 f28;
    u16 f2c, f2e;
} Menu;
extern void func_02082BCC(void *, int, u32);
extern void *func_021E88B0(Menu *, u8, u8, u8, u8, int);
void func_0217DEDC(char *p, int mode)
{
    Menu rec;
    int layout, x, y, width, height;
    if (*(int *)(p + 12) == 0) {
        func_02082BCC(&rec, 0, 0x30);
        rec.f00 = *(u32 *)p;
        rec.f04 = *(u32 *)(p + 0x1c);
        rec.f08 = *(u32 *)(p + 0x24);
        rec.f20 = 0; rec.f22 = 15; rec.f24 = 13; rec.f26 = 1;
        switch (mode) {
        case 0:
            rec.option0 = 0x76; rec.option1 = 0x77; rec.count = 2;
            rec.f28 = 1; rec.f2c = 1; layout = 0; rec.f2e = 1; break;
        case 1:
            rec.option0 = 0x74; rec.count = 1; rec.f28 = 1; rec.f2c = 0;
            layout = 0; break;
        case 2:
            rec.option0 = 0x75; rec.option1 = 0x74; rec.count = 2;
            rec.f28 = 1; rec.f2c = 1; layout = 1; rec.f2e = 1; break;
        }
        switch (layout) {
        case 0: height = rec.count * 2; width = 12; x = 19; y = 17 - height; break;
        case 1: height = rec.count * 2; width = 15; x = 16; y = 17 - height; break;
        }
        *(void **)(p + 12) = func_021E88B0(&rec, x, y, width, height, *(u16 *)(p + 0x34));
    }
}
