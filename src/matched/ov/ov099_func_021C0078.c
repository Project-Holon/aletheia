/*
 * function: func_021C0078
 * address: 0x021C0078
 * packet: pkt_ov099_021C0078
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: lead is 188 bytes; 021C0134, 021C0138, 021C013C are Thumb return-second-argument
 *   followers, each 08 1c 70 47 (adds r0,r1,#0; bx lr), not padding. ARM9 cap forbids filing them.
 * blocker: ARM9 GFL_NET_STATE_IsFatalError at +0006; concrete bytes match, no ARM9 source written.
 * blocker: scratch one --arm (no region), dsi/1.1p1 -O4,p: MATCH 52 bytes;
 *   _pNetState 0x021469DC data resolves, GFL_NET_STATE_FatalError 0x0203CADC arm remains unresolved.
 *   typedef struct { int pad[2]; void (*callback)(void); } Object;
 *   extern Object *_pNetState;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if(_pNetState && _pNetState->callback==GFL_NET_STATE_FatalError)return 1;
 *       return 0;
 *   }
 * blocker: nested scratch one --arm, same compiler/flags: GFL_NET_STATE_FatalError EXACT 36 bytes;
 *   file_020A7BA8 0x020A7BA8 data; message_020A7C7C 0x020A7C7C data;
 *   func_02034714 0x02034714 arm.
 *   extern const char file_020A7BA8[];
 *   extern const char message_020A7C7C[];
 *   extern void func_02034714(const char *,unsigned,const char *);
 *   void GFL_NET_STATE_FatalError(void) {
 *       func_02034714(file_020A7BA8,0x8d8,message_020A7C7C);
 *   }
 * diagnosis: caller-only tu --suggest-split MATCH 188 bytes; no viable split.
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
extern int GFL_NET_STATE_IsFatalError(void);
extern void func_021BE900(char *);
extern int func_021BA928(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 KEY_GetTrg(void);
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
extern void func_021B9AE0(void *w, u8 *s);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *,int,int);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_021BDD0C(void *p, int on);
extern int func_021B96CC(int *p);
extern int func_021BE4F0(char *,int);
extern void func_021C19A8(char *);
extern void func_021BAEDC(char *);
extern void func_021C2408(char *);
int func_021C0078(char *p,int ret)
{
    if(GFL_NET_STATE_IsFatalError()){func_021BE900(p);return ret;}
    if(!func_021BA928(p)){*(int *)(p+0x1e0)=30;return ret;}
    --*(int *)(p+0x1e0);
    if((KEY_GetTrg()&3)||!*(int *)(p+0x1e0)){
        func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
        func_021BA8EC(p);
        func_021C18C8(p,1,2);
        GFL_NET_STATE_WifiDisconnect(1);
        func_021BDD0C(p,0);
        if(!func_021B96CC((int *)(p+0x274))){
            *(int *)(p+0x1cc)=func_021BE4F0(p,0);
        }else{
            func_021C19A8(p);
            func_021BAEDC(p);
            *(int *)(p+0x1f0)=-1;
            *(int *)(p+0x1cc)=11;
            func_021C2408(p);
        }
    }
    return ret;
}
