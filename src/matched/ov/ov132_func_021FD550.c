/*
 * function: func_021FD550
 * address: 0x021FD550
 * packet: pkt_ov132_021FD550
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two-byte zero alignment padding at 021FD5E2.
 * symbols:
 *   func_021FCEA8 0x021FCEA8 thumb ov132
 *   func_021FD5E4 0x021FD5E4 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021FCEA8(void *,int,u32,int);
extern int func_021FD5E4(char *p, u32 i);
void func_021FD550(char *p)
{
    if(*(int *)(p+0x150)==1) {
        switch(*(u32 *)(p+0x17c)) {
        case 0: break;
        case 1:
            if(func_021FCEA8(p,7,*(u32 *)(*(char **)(p+0x140)+0x2c),0xff)==1) *(int *)(p+0x17c)=2;
            break;
        case 2: break;
        case 3:
            if(func_021FD5E4(p,*(u8 *)(p+0x14c))==1) {
                *(int *)(p+0x154)=1;
                *(int *)(p+0x17c)=4;
            }
            break;
        case 4:
            if(*(int *)(p+0x154)==0) {
                if((u32)(*(u8 *)(p+0x14c)*0x3800)>=*(u32 *)(*(char **)(p+0x140)+0x2c)) *(int *)(p+0x150)=0;
                else *(int *)(p+0x17c)=3;
            }
            break;
        }
    }
}
