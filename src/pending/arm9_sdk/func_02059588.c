/*
 * function: func_02059588
 * address:  0x02059588
 * packet:   pkt_02059588
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    4 bytes: the xor loop reads buffer[i] through the &buffer[i] base (ldr r1, [r0]); the image reads it indexed (ldr r1, [r4, r2, lsl #2]). Rest of the function is byte-identical.
 *
 * sdk:      DWCi_Acc_CreateTempLoginId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   OS_GetLowEntropyData             0x02088168 arm
 *   DWC_Auth_GetId                   0x02058fb4 arm
 *   DWCi_Acc_SetUserId               0x020590c8 arm
 *   DWCi_Acc_SetPlayerId             0x020590f0 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
 */

struct MATHCRC32Table {
    unsigned long table[256];
};

struct DWCstAccLoginId {
    unsigned long data[3];
};

struct DWCstAccUserData {
    unsigned long size;
    struct DWCstAccLoginId pseudo;
    struct DWCstAccLoginId authentic;
    int gs_profile_id;
    unsigned long flag;
    unsigned long gamecode;
    unsigned long reserved[5];
    unsigned long crc32;
};

extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
typedef struct DWCAuthWiFiId {
    unsigned long long uId;
    unsigned long long notAttestedId;
    unsigned long flg;
} DWCAuthWiFiId;

extern void DWC_Auth_GetId(DWCAuthWiFiId *id);
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);

typedef struct MATHRandContext32 {
    unsigned long long x;
    unsigned long long mul;
    unsigned long long add;
} MATHRandContext32;

static inline void MATH_InitRand32(MATHRandContext32 *context, unsigned long long seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}

static inline unsigned long MATH_Rand32(MATHRandContext32 *context, unsigned long max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (unsigned long)(context->x >> 32);
    }
    return (unsigned long)(((context->x >> 32) * max) >> 32);
}

extern void OS_GetLowEntropyData(unsigned long *buffer);
extern void DWCi_Acc_SetUserId(struct DWCstAccLoginId *userdata, unsigned long long userid);
extern void DWCi_Acc_SetPlayerId(struct DWCstAccLoginId *userdata, unsigned long playerid);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);

void func_02059588(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;
    unsigned long buffer[8];
    MATHRandContext32 context;
    unsigned long i;

    OS_GetLowEntropyData(buffer);
    for (i = 1; i < 8; i++) {
        buffer[i] ^= buffer[i - 1];
    }
    MATH_InitRand32(&context, buffer[7]);
    DWC_Auth_GetId(&authid);
    if (authid.flg) {
        DWCi_Acc_SetUserId(loginid, authid.uId);
    } else {
        DWCi_Acc_SetUserId(loginid, authid.notAttestedId);
    }
    DWCi_Acc_SetPlayerId(loginid, MATH_Rand32(&context, 0));
    DWCi_Acc_SetFlag_DataType(loginid, 1);
}
