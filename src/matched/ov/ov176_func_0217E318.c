/*
 * function: func_0217E318
 * address: 0x0217E318
 * packet: pkt_ov176_0217E318
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   func_02034714 0x02034714 arm
 *   d_0217E64C 0x0217E64C data a1
 *   DELIVERY_IRC_Create 0x02157DD8 thumb ov010
 */
#include "../include/Obj08287.h"
typedef struct {
    unsigned a;
    unsigned short b, heap;
    unsigned c, value, byte, flags;
    unsigned pad[24];
    unsigned last;
} Config;
extern void func_02082BCC(void *, int, unsigned);
extern unsigned char GAME_LANGUAGE_Code;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E64C[];
typedef unsigned char  u8;
extern void *DELIVERY_IRC_Create(u8 *p);
void func_0217E318(char *p, unsigned value)
{
    Config config;
    func_02082BCC(&config, 0, 0x7C);
    config.a = 0x30;
    config.c = 0x160;
    config.value = value;
    config.b = 0;
    config.heap = ((struct Obj08287 *)p)->f4;
    config.byte = GAME_LANGUAGE_Code;
    config.flags = 0x200000;
    config.last = 1;
    if (((struct Obj08287 *)p)->f1018)
        func_02034714(d_0217E64C, 0, d_0217E64C);
    ((struct Obj08287 *)p)->f1018 = DELIVERY_IRC_Create((u8 *)(&config));
    ((struct Obj08287 *)p)->f0 = 0;
}
