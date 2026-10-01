/*
 * unit: yes
 * function: func_021BEDCC,func_021BEE04,func_021BEE14
 * address: 0x021BEDCC
 * packet: pkt_ov203_021BEDCC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020062BC 0x020062BC thumb
 *   func_02006268 0x02006268 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005D28 0x02005D28 thumb
 */
extern void func_020062BC(int,unsigned);
extern void func_02006268(int,unsigned,unsigned,unsigned);
extern void func_02005D90(int,int);
extern void func_02005D28(void);
void func_021BEDCC(int mode,int channel,int value)
{
    switch(mode){case 0:func_020062BC(channel,value);break;case 1:func_02006268(channel,-1,-1,value);break;case 2:func_02006268(channel,-1,value,-1);break;}
}
void func_021BEE04(int a,int b,int *s){func_02005D90(s[0],0xffff);}
void func_021BEE14(void){func_02005D28();}
