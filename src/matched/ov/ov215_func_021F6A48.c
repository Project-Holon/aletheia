/*
 * function: func_021F6A48
 * address: 0x021F6A48
 * packet: pkt_ov215_021F6A48
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015F50 0x02015F50 thumb
 *   func_021F6CAC 0x021F6CAC thumb ov215
 *   func_021F6AEC 0x021F6AEC thumb ov215
 *   func_021F6CCC 0x021F6CCC thumb ov215
 */
typedef unsigned char u8;
struct McssFade;
extern void func_02015EA0(void *);
extern void func_02015F50(struct McssFade *,u8,u8,int,unsigned);
extern void func_021F6CAC(char *);
extern void func_021F6AEC(char *);
extern void func_021F6CCC(char *,unsigned,int);
void func_021F6A48(char *p,int a)
{
    func_021F6CAC(p);
    *(int *)(p + 4) = a;
    func_021F6AEC(p);
    func_021F6CCC(p,0,0);
    func_02015EA0(*(void **)(p + 0x34));
    func_02015F50(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}
