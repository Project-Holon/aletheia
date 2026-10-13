/*
 * function: func_021BF2C4
 * address: 0x021BF2C4
 * packet: pkt_ov099_021BF2C4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 at +001A lacks an outside code witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BFB04.c, itself copied from ov099_func_021BEB68.c
 *   (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 * shape: the nested record test preserves its branch-to-branch;
 *   the named call-result value fixes cmp r0,r1 at +0176.
 * prototype: 021C1968 tail forwards the result read by this caller;
 *   0203D7B0/0203D7BC keep the visible r0 argument; 021C2864's
 *   r1 stays full-width because neither call site truncates it.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_02005728 0x02005728 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   func_02082D44 0x02082D44 arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BF280 0x021BF280 thumb ov099
 *   func_021C1BEC 0x021C1BEC thumb ov099
 *   func_021B9B54 0x021B9B54 thumb ov099
 *   func_021B98FC 0x021B98FC thumb ov099
 *   func_021C1968 0x021C1968 thumb ov099
 *   func_021C1A30 0x021C1A30 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 *   func_021C1B04 0x021C1B04 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B989C 0x021B989C thumb ov099
 *   func_021BF29C 0x021BF29C thumb ov099
 *   func_021B98F0 0x021B98F0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C27F8 0x021C27F8 thumb ov099
 *   func_021C2874 0x021C2874 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   func_021BF068 0x021BF068 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021B96D0 0x021B96D0 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021B9B24 0x021B9B24 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern int GFL_NET_STATE_GetWifiState(void);
typedef signed short   s16;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern u32 KEY_GetTrg(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 func_02005728(u32);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void func_02082D44(void *, void *, int);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern int DWC_RAP_GetNewClientAid(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern s16 DWC_RAP_GetVchatEnabled(void);
extern void func_021BE900(char *);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BAEDC(char *);
extern void func_021C18C8(char *, int, int);
extern void func_021BF280(void *a, void *b);
extern void func_021C1BEC(u8 *p);
extern void func_021B9B54(char *);
extern u32 func_021B98FC(char *);
extern int func_021C1968(char *);
extern void func_021C1A30(u8 *p, int v);
extern void func_021C19DC(char *, int);
extern u8 func_021C1B04(char *, int);
extern void *func_021BE2A8(char *, int);
extern void func_021B989C(void *, void *);
extern void func_021BF29C(char *);
extern void func_021B98F0(void *p);
extern int func_021C23B8(int i);
extern int func_021C27F8(char *p, char *q);
extern int func_021C2874(void *);
extern u8 func_021BDD48(char *, void *);
extern u8 func_021BDD54(char *, void *);
extern int func_021BDDA8(int x);
extern int func_021BF03C(char *);
extern int func_021BF068(char *);
extern int func_021C27E0(void *);
extern void func_021C2864(void *, int);
extern u32 func_021B96D0(char *);
extern void func_021B9B64(char *);
extern void func_021B9B24(char *);
extern u8 func_021B97F4(char *);
int func_021BF2C4(char *p, int ret)
{
    u32 action = 0, kind;
    int index, i, key, value;
    void *record;
    *(u8 *)(p + 0x1356) = 0;
    if (WIPE_SYS_EndCheck() == 0) return ret;
    if (GFL_NET_STATE_IsFatalError()) { func_021BE900(p); return ret; }
    if (*(int *)(p + 0x1f0) != -1) {
        if (++*(int *)(p + 0x1c8) > 0xe10) { GFL_NET_STATE_SetError(0, 0, 0, 0x3f1); return ret; }
    }
    if (GFL_NET_STATE_GetWifiState() == 4) {
        func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 21;
        func_021C18C8(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        return ret;
    }
    func_021BF280(p, (void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p + 0x274);
    if (func_021B98FC(p + 0x274) == 0) {
        if (DWC_RAP_GetNewClientAid() == -1 && (KEY_GetTrg() & 0x400)) {
            if (func_021C1968(p)) func_021BAADC(p, 57, 0);
            else func_021BAADC(p, 58, 0);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BAEDC(p);
            *(int *)(p + 0x1cc) = 12;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        key = func_021C1B04(p, 33);
        record = func_021BE2A8(p, key);
        if (key != 0) {
            if (record != 0) func_021B989C(p + 0x274, record);
            else { func_021BF29C(p); func_021B98F0(p + 0x274); }
        } else { func_021BF29C(p); func_021B98F0(p + 0x274); }
    }
    for (i = 0; i < 32; i++) {
        index = func_02005728(32);
        if (func_021C27F8(*(void **)(p + 8), (char *)func_021C23B8(index)) != 0) {
            value = func_021C2874((void *)func_021C23B8(index));
            if (value != *(*(u8 **)(p + 0x248) + index + 0x24)) {
            func_021BDD48(p, (void *)func_021C23B8(index));
            func_021BDD54(p, (void *)func_021C23B8(index));
            *(u16 *)(p + 0x242) = index + 1;
            GFL_USE_PlaySeInSlot((void *)0x806, 0);
            *(int *)(p + 0x1cc) = 63;
            return ret;
            }
        }
    }
    if (func_021BF03C(p) && *(int *)(p + 0x1f0) != -1) {
        GFL_USE_PlaySeInSlot((void *)0x806, 0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        *(int *)(p + 0x1cc) = 40;
        return ret;
    }
    if (*(int *)(p + 0x1f0) == -1 && DWC_RAP_GetNewClientAid() != -1) {
        index = DWC_RAP_GetNewClientAid();
        *(int *)(p + 0x1f0) = index;
        func_021BA874(p, index);
        if (!*(u8 *)(p + 0x1351)) func_021BAAB8(p, 46, 0);
        *(int *)(p + 0x1c8) = 0;
    } else if (*(int *)(p + 0x1f0) != -1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0(*(void **)(p + 8)));
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        GFL_NET_STATE_WifiDisconnect(1);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (func_021BF068(p) && *(int *)(p + 0x1f0) != -1) {
        func_021BA874(p, DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (DWC_RAP_GetVchatEnabled() == 1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        func_021C2864(*(void **)(p + 8), func_021C27E0(*(void **)(p + 8)));
    }
    kind = func_021BDD48(p, *(void **)(p + 8));
    if (*(int *)(p + 0x1f0) == -1) {
        if ((KEY_GetTrg() & 2) && func_021BDDA8(kind)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            *(int *)(p + 0x1cc) = 31;
            func_021C19DC(p, 33);
            return ret;
        }
        action = func_021B96D0(p + 0x274);
        func_021B9B64(p + 0x274);
    }
    switch (action) {
    case 0: return ret;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (func_021BDDA8(kind)) *(int *)(p + 0x1cc) = 31;
        else {
            *(int *)(p + 0x1d0) = 0;
            *(int *)(p + 0x1cc) = 49;
            func_021BAAB8(p, 25, 1);
        }
        func_021C1A30((u8 *)p, 33);
        return ret;
    case 3:
        if (kind == 1) {
            *(int *)(p + 0x135c) = 1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021B9B24(p + 0x274);
            *(int *)(p + 0x1cc) = 28;
            func_021C1A30((u8 *)p, 33);
            *(u8 *)(p + 0x1351) = 0;
            return ret;
        }
        break;
    case 2:
        if (kind == 1) {
            index = func_021B97F4(p + 0x274);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_02082D44((void *)func_021C23B8(index - 1), p + 0x24c, 32);
            *(int *)(p + 0x1cc) = 34;
            func_021C1A30((u8 *)p, 33);
            return ret;
        }
        break;
    }
    return ret;
}
