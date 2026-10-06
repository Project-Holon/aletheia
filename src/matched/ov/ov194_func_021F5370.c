/*
 * function: func_021F5370
 * address: 0x021F5370
 * packet: pkt_ov194_021F5370
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_0204A298 0x0204A298 arm
 *   func_0203F37C 0x0203F37C arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F546C 0x021F546C thumb ov194
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082D44(const void *,void *,unsigned);
extern int func_0204A298(int,int,int,int,u32 *);
extern void func_0203F37C(void *p, unsigned int size, unsigned int seed);
extern void func_020307B0(void *p);
extern int func_021F546C(const u16 *a, u32 b, u32 c, const u16 *d, u32 n);
int func_021F5370(const u32 *cache,const void *input,u16 heap)
{
    u16 buf[32]={0};
    u32 size;
    int i,result;
    u32 data;
    func_02082D44(input,buf,64);
    for(i=0;i<32;i++) {
        u32 c=buf[i];
        if(c>=0x30a1 && c<=0x30f4) buf[i]=c-0x60;
        else if(c>=0x61 && c<=0x7a) buf[i]=c-0x20;
        else if(c>=0xff41 && c<=0xff5a) buf[i]=c-0xff00;
        else if(c>=0xff21 && c<=0xff3a) buf[i]=c-0xfee0;
        else if(c>=0xe0 && c<=0xfe) buf[i]=c-0x20;
    }
    for(i=0;i<7;i++) {
        if(cache==0) {
            data=func_0204A298(0xdd,i,0,heap,&size);
            func_0203F37C((void *)data,size,0x72012891);
        } else {data=cache[i];size=cache[i+7];}
        { u32 currentHeap=heap; result=func_021F546C(buf,i,currentHeap,(const u16 *)data,size); }
        if(cache==0) func_020307B0((void *)data);
        if(result==1) break;
    }
    return result;
}
