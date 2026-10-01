/*
 * function: func_021BBCB0
 * address: 0x021BBCB0
 * packet: pkt_ov217_021BBCB0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: arm9 0x0200E440 lacks a witness outside this caller; scratch E440-blocker-r2.log proves EXACT 10 bytes. Ilias owns filing.
 * blocker C: typedef unsigned char u8; void func_0200E440(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 * symbols:
 *   func_021BC6E4 0x021BC6E4 thumb ov217
 *   func_021BC628 0x021BC628 thumb ov217
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E440 0x0200E440 thumb
 *   d_021C30A8 0x021C30A8 data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C308A 0x021C308A data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Big;
extern u32 func_021BC6E4(void *p);
extern u32 func_021BC628(u8 *p);
extern void *func_02012EBC(struct Big *p);
extern int func_0200E394(int p);
extern void func_0200E440(int p,int value,int index);
extern const u8 d_021C30A8[],d_021C3080[],d_021C308A[];
void func_021BBCB0(u8 *p)
{
    u32 index;
    int data;
    index=func_021BC6E4(p);
    data=func_0200E394((int)func_02012EBC((struct Big *)func_021BC628(p)));
    func_0200E440(data,d_021C30A8[index],0);
    func_0200E440(data,d_021C3080[index],1);
    func_0200E440(data,d_021C308A[index],2);
}
