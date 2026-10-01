/*
 * function: func_021BABA4, func_021BABB8
 * unit: yes
 * address: 0x021BABA4
 * packet: pkt_ov214_021BABA4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * function_starts: 0x021BABB8
 * note: Cleared BABB8 follower occupies 60 bytes through BABF4. The pools
 * at BABEC/BABF0 point to the two fields of the same byte-pair table.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 *   d_021BB4C4 0x021BB4C4 data a1
 */
typedef unsigned char u8;
typedef struct {u8 a,b;} Pair;
extern const Pair d_021BB4C4[];
extern void func_0204B3B4(void*);
extern void func_021B6284(void*);
void func_021BABA4(void*p,void*actor)
{
    func_0204B3B4(actor);
    func_021B6284(p);
}
void func_021BABB8(int unused,char*p)
{
    u8 i=*(unsigned*)(p+0x2b0);
    if(i>=0x29)i=0;
    *(unsigned*)(p+0x2a4)=d_021BB4C4[i].a;
    if(d_021BB4C4[i].b==0)*(unsigned*)(p+0x2a8)=1;
    else *(unsigned*)(p+0x2a8)=0;
}
