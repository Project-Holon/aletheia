/*
 * function: func_021F6630
 * address: 0x021F6630
 * packet: pkt_ov215_021F6630
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021F6328 0x021F6328 thumb ov215
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021F7160 0x021F7160 data a4
 *   d_021F7154 0x021F7154 data a4
 *   d_021F716C 0x021F716C data a4
 * evidence: 46440 heap extern widened; original stores full r1 at sp+4.
 */
typedef signed short s16;
typedef unsigned short u16;
struct Vec3 { unsigned x,y,z; };
extern const s16 d_020A1EB8[];
extern const struct Vec3 d_021F7160,d_021F7154,d_021F716C;
extern void func_021F6328(void);
extern void func_02046440(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,const struct Vec3 *,const struct Vec3 *,const struct Vec3 *,u16);
void func_021F6630(void **out,u16 heap)
{
    func_02046440(0,2,0,1,0,heap,func_021F6328);
    *out=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,4194304,0,&d_021F7160,&d_021F7154,&d_021F716C,heap);
}
