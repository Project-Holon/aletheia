/*
 * function: func_021BBA74
 * address: 0x021BBA74
 * packet: pkt_ov225_021BBA74
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BBC44 retains original visible r0 context although its fixed tail ignores it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   file_021BC06C 0x021BC06C data a1
 *   func_021BBBF4 0x021BBBF4 thumb ov225
 *   func_021BBC44 0x021BBC44 thumb ov225
 *   func_021BBC54 0x021BBC54 thumb ov225
 *   func_021BBBF0 0x021BBBF0 thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_021BA0F0 0x021BA0F0 thumb ov225
 *   func_021BBD74 0x021BBD74 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const char file_021BC06C[];
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_021BBBF4(char *);
extern void func_021BBC44(char *);
extern void func_021BBC54(u8 *);
extern void func_021BBBF0(void *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BA068(char *, unsigned);
extern void func_021BA0F0(char *, unsigned, unsigned);
extern void func_021BBD74(char *);
char *func_021BBA74(char *p, char *data)
{
    char *q;
    q = func_02030734(*(u16 *)(data + 4), 64, 1, file_021BC06C, 156);
    *(char **)q = p;
    *(unsigned *)(p + 0x28) = 0;
    *(char **)(q + 4) = data;
    q[8] = 0;
    *(unsigned *)(q + 0xc) = 0;
    func_021BBBF4(q);
    func_021BBC44(q);
    func_021BBC54((u8 *)q);
    *(void **)(q + 0x34) = func_020056A0((unsigned)func_021BBBF0, (unsigned)q, 1);
    *(unsigned *)(q + 0x38) = 0;
    q[0x3c] = -1;
    func_021BA068(*(char **)(*(char **)(q + 4) + 0x34), 3);
    func_021BA0F0(*(char **)(*(char **)(q + 4) + 0x34), *(u8 *)*(char **)q, *(u8 *)(q + 8));
    func_021BBD74(q);
    return q;
}
