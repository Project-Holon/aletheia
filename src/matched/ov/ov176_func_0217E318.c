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
 *   d_0209DF0C 0x0209DF0C data a1
 *   func_02034714 0x02034714 arm
 *   d_0217E64C 0x0217E64C data a1
 *   func_02157DD8 0x02157DD8 thumb ov010
 */
typedef struct {
    unsigned a;
    unsigned short b, heap;
    unsigned c, value, byte, flags;
    unsigned pad[24];
    unsigned last;
} Config;
extern void func_02082BCC(void *, int, unsigned);
extern unsigned char d_0209DF0C;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E64C[];
extern void *func_02157DD8(Config *);
void func_0217E318(char *p, unsigned value)
{
    Config config;
    func_02082BCC(&config, 0, 0x7C);
    config.a = 0x30;
    config.c = 0x160;
    config.value = value;
    config.b = 0;
    config.heap = *(unsigned short *)(p + 4);
    config.byte = d_0209DF0C;
    config.flags = 0x200000;
    config.last = 1;
    if (*(void **)(p + 0x1018))
        func_02034714(d_0217E64C, 0, d_0217E64C);
    *(void **)(p + 0x1018) = func_02157DD8(&config);
    *(int *)p = 0;
}
