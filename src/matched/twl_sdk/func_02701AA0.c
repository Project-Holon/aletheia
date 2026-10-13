/*
 * function: CameraPxiCallback
 * address:  0x02701AA0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_02087988  0x02087988  arm twl a2
 *   func_0208799C  0x0208799C  arm twl a2
 *   CameraCallCallbackAndUnlock  0x02701FE8  arm twl a2
 *   CAMERA_GoReboot  0x027001F0  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

#define reg_04004004 (*(volatile u16 *)0x04004004)

typedef struct CamPxiCmd {
    u32 busy;
    u32 callback;
    u32 f08;
    u32 arg;
    s32 command;
    s32 type;
    u8 index;
    u8 total;
    u8 pad[2];
    u8 *buf;
    u32 len;
    u32 pend0;
    u32 pend1;
    u32 pend2;
} CamPxiCmd;

typedef struct CamPxiState {
    u8 pad0[0x128];
    s32 f128, f12c, f130, f134, f138, f13c, f140, f144;
    s32 f148, f14c, f150, f154, f158, f15c, f160, f164;
    s32 f168, f16c, f170, f174, f178, f17c, f180, f184;
    s32 f188, f18c, f190, f194, f198, f19c;
    u32 flagsA;
    u32 flagsB;
    s32 value;
} CamPxiState;

extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void CameraCallCallbackAndUnlock(u32);
extern void CAMERA_GoReboot(void);
extern CamPxiCmd data_02732FC8;
extern CamPxiState data_02733FC8;

void CameraPxiCallback(int tag, u32 data, int err)
{
    u32 result;
    u8 *buf;

    if (err) {
        CameraCallCallbackAndUnlock(7);
        return;
    }
    if (data & 0x2000000) {
        data_02732FC8.total = (data & 0xff0000) >> 16;
        data_02732FC8.index = 0;
        data_02732FC8.command = (data & 0x7f00) >> 8;
        data_02732FC8.type = data & 0xff;
    } else {
        buf = data_02732FC8.buf;
        if (buf == 0) {
            CameraCallCallbackAndUnlock(7);
            return;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            buf[data_02732FC8.index++] = (data & 0xff0000) >> 16;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = (data & 0xff00) >> 8;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = data;
        }
    }
    if (data_02732FC8.index < data_02732FC8.total - 1) {
        return;
    }
    if (data_02732FC8.pend2 != 0 || (data_02732FC8.pend1 == 0 && data_02732FC8.pend0 == 0)) {
        u32 irq = func_02087988();
        reg_04004004 = reg_04004004 & ~0x100;
        func_0208799C(irq);
    }
    result = 0;
    data_02732FC8.pend1 = result;
    data_02732FC8.pend2 = result;
    switch (data_02732FC8.type) {
    case 0:
        switch (data_02732FC8.command) {
        case 0x10:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        case 0x12:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f15c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f198 = data_02733FC8.value;
            break;
        case 0x30:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f128 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f12c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f164 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f168 = data_02733FC8.value;
            break;
        case 0x31:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f148 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f184 = data_02733FC8.value;
            break;
        case 0x32:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f130 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f134 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f16c = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f170 = data_02733FC8.value;
            break;
        case 0x33:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f138 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f13c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f174 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f178 = data_02733FC8.value;
            break;
        case 0x34:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f140 = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f150 = 0;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 1:
                    data_02733FC8.f150 = -2;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 2:
                    data_02733FC8.f150 = 1;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 3;
                    break;
                case 3:
                    data_02733FC8.f150 = -1;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                case 4:
                    data_02733FC8.f150 = 2;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                }
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f17c = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f18c = 0;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 1:
                    data_02733FC8.f18c = -2;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 2:
                    data_02733FC8.f18c = 1;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 3;
                    break;
                case 3:
                    data_02733FC8.f18c = -1;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                case 4:
                    data_02733FC8.f18c = 2;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                }
            }
            break;
        case 0x35:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f144 = data_02733FC8.value;
                data_02733FC8.f158 = 1;
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f180 = data_02733FC8.value;
                data_02733FC8.f194 = 1;
            }
            break;
        case 0x36:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f14c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f188 = data_02733FC8.value;
            break;
        case 0x37:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f150 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f18c = data_02733FC8.value;
            break;
        case 0x39:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f154 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f190 = data_02733FC8.value;
            break;
        case 0x3a:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f158 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f194 = data_02733FC8.value;
            break;
        case 0x40:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        }
        break;
    case 1:
        result = 1;
        break;
    case 4:
        result = 6;
        break;
    case 2:
    case 3:
    case 5:
    default:
        result = 7;
        break;
    }
    CameraCallCallbackAndUnlock(result);
    if (result == 6) {
        CAMERA_GoReboot();
    }
}








