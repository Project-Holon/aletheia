/*
 * file:     btl_adapter.c
 * unit:     yes
 * function: func_021EEA30, func_021EEA54, func_021EEA58, func_021EEAD0, func_021EEAE0, func_021EEAE8, func_021EEAFC, func_021EEB00, func_021EEB2C, func_021EEB64, func_021EEB70, func_021EEB84, func_021EEBA4, func_021EEBDC, func_021EEBE8, func_021EEC20, func_021EEC4C, func_021EEC78, func_021EECD8, func_021EED00, func_021EED24, func_021EED48, func_021EED6C, func_021EED90, func_021EEE24, func_021EEE80, func_021EEEC8, func_021EEEF4, func_021EEF20, func_021EEF98, func_021EEFE0, func_021EF1CC, func_021EF204, func_021EF280, func_021EF3A4, func_021EF460, func_021EF508, func_021EF594, func_021EF5E8, func_021EF664, func_021EF694, func_021EF6A8, func_021EF6B0, func_021EF6E8, func_021EF6F0, func_021EF71C, func_021EF7AC
 * address:  0x021EEA30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0   0x020307B0  arm arm9
 *   func_02082D44  0x02082D44  arm
 *   d_021F6388  0x021F6388  data  a4
 *   d_021F6384  0x021F6384  data  a4
 *   d_021F3AE8     0x021F3AE8  data  ov093  a4
 *   func_021D4C58   0x021D4C58  thumb
 *   func_021D4B58  0x021D4B58  thumb  ov093
 *   func_021D4B98  0x021D4B98  thumb  ov093
 *   func_021D4BD4  0x021D4BD4  thumb  ov093
 *   func_021D4C60  0x021D4C60  thumb  ov093
 *   func_021D4C6C  0x021D4C6C  thumb  ov093
 *   func_021D4C84  0x021D4C84  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F3990     0x021F3990  data  ov093  a2
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_0201EE84  0x0201EE84  thumb
 *   func_021BA020  0x021BA020  thumb  ov093
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021B9FAC  0x021B9FAC  thumb  ov093
 *   func_021BA064  0x021BA064  thumb  ov093
 *   func_021BA080  0x021BA080  thumb  ov093
 *   func_0202A3CC  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 *   d_021F39A0     0x021F39A0  data  a2
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F39D8  0x021F39D8  data  a4
 *   func_02045A98  0x02045A98  arm
 *   func_0201D5C4  0x0201D5C4  thumb
 *   func_0201D5CC  0x0201D5CC  thumb
 *   func_0201D670  0x0201D670  thumb
 *   func_0201D5F4  0x0201D5F4  thumb
 *   func_0201D658  0x0201D658  thumb
 *   func_0201D688  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F020 0x0201F020 thumb
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 */

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef char *va_list;

struct BtlSystem;
struct BtlPokeList;
struct BtlPoke;
struct WordSet;
struct MsgBank;
struct Strbuf;

/* Wire packet of the adapter: command, size of data, then the data. */
struct BtlAdapterPacket {
    u16 command;
    u16 size;
    u8 data[0xBD0 - 0x14];
};

/*
 * One command channel between the battle logic and the net layer (0xBD0
 * bytes, one per channel in gBtlAdapterSlots). Channel 0 of a local battle
 * has netId 0 and loops the data back through peerData/packetData; with a
 * non-zero netId the data goes through the net functions instead.
 */
typedef struct BtlAdapter {
    u32 owner;                  /* 0x00 */
    const u8 *peerData;         /* 0x04 data the other side supplied (local mode) */
    u32 peerSize;               /* 0x08 */
    u8 peerReady : 4;           /* 0x0c */
    u8 netId : 4;
    u8 channel;                 /* 0x0d */
    u8 phase;                   /* 0x0e send state: 0 idle, 1 sending, 3 waiting, 4 done */
    u8 commandByte;             /* 0x0f */
    struct BtlAdapterPacket packet; /* 0x10 packet sent to the net layer */
} BtlAdapter;

/* Message formatter state (d_021F6398). */
struct BtlMsgState {
    struct BtlSystem *battle;       /* 0x00 */
    struct BtlPokeList *pokeList;   /* 0x04 */
    struct WordSet *wordSet;        /* 0x08 */
    struct Strbuf *msgBuf;          /* 0x0c */
    struct MsgBank *banks[8];       /* 0x10 */
    u32 args[8];                    /* 0x30 argument table of the variadic builder */
    u16 heapId;                     /* 0x50 */
    u16 pad52;
    u32 clientId;                   /* 0x54 viewing client */
    u16 plainWording;               /* 0x58 nonzero: skip the own/foe/ally wording */
    u16 useSpeciesName;             /* 0x5a nonzero: pokemon tags print the species */
};

/* Table of tags with their own builder (d_021F39D8). */
struct BtlMsgBuilder {
    u16 tag;
    u16 pad;
    void (*build)(struct Strbuf *dest, u32 msgId, u32 *args);
};

/* Argument block of BTL_MSG_BuildMoveEffectA. */
typedef struct {
    u32 clientId;
    u32 value;
    int entry;
    int tier;
} BtlMsgEffectArgsA;

/* Argument block of BTL_MSG_BuildMoveEffectB. */
typedef struct {
    u32 clientId;
    int entry;
    int tier;
} BtlMsgEffectArgsB;

extern u32 func_020307B0(void *block);
extern void func_02082D44(const void *src, void *dest, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021D4C58(u32 netId);
extern u32 func_021D4B58(u32 channel, struct BtlAdapterPacket *packet, u32 size);
extern int func_021D4B98(void);
extern u16 func_021D4BD4(int channel, const u8 **outData);
extern u8 func_021D4C60(void);
extern u16 func_021D4C6C(struct BtlAdapterPacket **outPacket);
extern u32 func_021D4C84(const u8 *data, u32 size);
extern int func_021BA1A8(struct BtlSystem *battle, int flag);
extern struct WordSet *func_0201EC64(u32 heapId);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern void func_02045808(struct Strbuf *buf);
extern u32 func_02045C04(struct MsgBank *bank);
extern struct BtlPoke *func_021B9940(struct BtlPokeList *list, u8 pokeId);
extern void *func_021D5864(struct BtlPoke *poke);
extern void func_0201EEF4(struct WordSet *wordSet, u32 slot, void *mon);
extern void *func_021D5844(struct BtlPoke *poke);
extern void func_0201EE84(struct WordSet *wordSet, u32 slot, void *mon);
extern unsigned short func_021BA020(struct BtlSystem *battle, int clientId);
extern void func_0201F0F8(struct WordSet *wordSet, u32 slot, u32 value);
extern int func_021B9F70(struct BtlSystem *battle, int clientId);
extern int func_021B86B8(struct BtlSystem *battle);
extern u16 func_021BA004(struct BtlSystem *battle, int clientId);
extern const void *func_021B9FAC(struct BtlSystem *battle, int clientId, u32 *outClass);
extern struct Strbuf *func_021BA064(struct BtlSystem *battle, int clientId);
extern struct Strbuf *func_021BA080(struct BtlSystem *battle);
extern u8 func_0202A3CC(u32 trainerClass);
extern void func_0201EE0C(struct WordSet *wordSet, u32 slot, const void *src, u32 classType, u32 nameMode, u32 nameFlags);
extern void func_0201F02C(struct WordSet *wordSet, u32 slot, struct Strbuf *src);
extern void func_0201F134(struct WordSet *wordSet, u32 slot, u32 value);
extern int func_021B8BD0(struct BtlSystem *battle, unsigned char clientId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dest, struct Strbuf *src);
extern u16 func_02045A98(void);
extern u32 func_0201D5C4(void);
extern u32 func_0201D5CC(const u16 *tag);
extern u32 func_0201D670(const u16 *tag, u32 index);
extern u32 func_0201D5F4(const u16 *tag);
extern u32 func_0201D658(const u16 *tag);
extern u16 *func_0201D688(u16 *tag);
extern u16 *STRBUF_GetChars(struct Strbuf *buf);
extern void func_0201EFA4(struct WordSet *wordSet, u32 slot, u32 value, u32 digits, u32 padding, u32 charSet);
extern void func_0201EF8C(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF34(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201EF40(struct WordSet *wordSet, u32 slot, u32 value);
extern void func_0201F020(struct WordSet *wordSet, u32 slot, u32 value);
extern u8 func_021B8DDC(u32 clientId);
extern int func_021B8CE8(struct BtlSystem *battle, int clientId, int side);
extern u8 func_021B8FF4(struct BtlSystem *battle);

extern BtlAdapter *d_021F6388[];
extern int d_021F6384;
extern const char d_021F3AE8[];
extern struct BtlMsgState d_021F6398;
extern const u16 d_021F3990[];
extern const u16 d_021F39A0[];
extern struct BtlMsgBuilder d_021F39D8[];

void func_021EEA30(int mode);
void func_021EEA54(void);
BtlAdapter *func_021EEA58(u32 owner, int channel, u32 netId, u32 heapId);
void func_021EEAD0(BtlAdapter *adapter);
void func_021EEAE0(BtlAdapter *adapter);
void func_021EEAE8(void);
void func_021EEAFC(void);
void func_021EEB00(BtlAdapter *adapter, u16 command, const void *src, u16 size);
int func_021EEB2C(BtlAdapter *adapter);
const u8 *func_021EEB64(BtlAdapter *adapter, u32 *outSize);
void func_021EEB70(BtlAdapter *adapter);
u32 func_021EEB84(BtlAdapter *adapter);
u32 func_021EEBA4(BtlAdapter *adapter);
void func_021EEBDC(BtlAdapter *adapter);
u8 func_021EEBE8(BtlAdapter *adapter);
u16 func_021EEC20(BtlAdapter *adapter, u8 **outData);
u32 func_021EEC4C(BtlAdapter *adapter, const u8 *data, u32 size);
void func_021EEC78(struct BtlSystem *battle, u32 clientId, struct BtlPokeList *pokeList, u32 heapId);
void func_021EECD8(void);
void func_021EED00(u8 pokeId, u32 slot);
void func_021EED24(u8 pokeId, u32 slot);
void func_021EED48(u8 pokeId, u8 slot);
void func_021EED6C(struct WordSet *wordSet, u8 slot, u8 clientId);
void func_021EED90(struct WordSet *wordSet, u8 slot, u8 clientId);
void func_021EEE24(struct Strbuf *dest, u16 msgId, u32 argCount, ...);
void func_021EEE80(struct Strbuf *dest, u16 msgId, u32 *args);
void func_021EEEC8(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EEEF4(struct Strbuf *dest, u16 msgId, u32 *args);
u16 *func_021EEF20(u16 *text, u32 *outGroup, u16 *outKind, u8 *outSlot);
u8 func_021EEF98(struct Strbuf *text);
void func_021EEFE0(struct Strbuf *text, const u32 *values, struct WordSet *wordSet);
void func_021EF1CC(struct Strbuf *dest, u16 msgId, u32 *args);
void func_021EF204(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF280(struct Strbuf *dest, u16 msgId, u32 *args);
void func_021EF3A4(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsA *args);
void func_021EF460(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsB *args);
void func_021EF508(struct Strbuf *dest, int msgId, u32 *args);
void func_021EF594(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF5E8(struct Strbuf *dest, u8 clientId, u16 entry);
void func_021EF664(struct Strbuf *dest, u16 entry, int alternate);
void func_021EF694(struct Strbuf *dest, u32 msgId);
void func_021EF6A8(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF6B0(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF6E8(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF6F0(struct Strbuf *dest, u32 msgId, u32 *args);
void func_021EF71C(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);
void func_021EF7AC(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);

void func_021EEA30(int mode)
{
    int i;

    for (i = 0; i < 4; i++)
        d_021F6388[i] = 0;
    d_021F6384 = mode;
}


void func_021EEA54(void) { }


BtlAdapter *func_021EEA58(u32 owner, int channel, u32 netId, u32 heapId)
{
    BtlAdapter *adapter;

    adapter = 0;
    if (d_021F6388[channel] == 0) {
        adapter = func_02030734(heapId, sizeof(BtlAdapter), 1, d_021F3AE8, 0x7e);
        adapter->owner = owner;
        adapter->channel = channel;
        adapter->netId = (u8)netId;
        adapter->phase = 0;
        adapter->commandByte = 0;
        adapter->peerReady = 0;
    }
    if (d_021F6384 == 0) {
        if (d_021F6388[channel] == 0)
            d_021F6388[channel] = adapter;
        return d_021F6388[channel];
    }
    d_021F6388[channel] = adapter;
    return adapter;
}


/* 021EEAD0  clear the peer-ready nibble and the phase and command bytes */
void func_021EEAD0(BtlAdapter *adapter)
{
    adapter->phase = 0;
    adapter->commandByte = 0;
    adapter->peerReady = 0;
}


void func_021EEAE0(BtlAdapter *adapter)
{
    func_020307B0(adapter);
}


/* 021EEAE8  call through a global pointer when it is set */
void func_021EEAE8(void)
{
    u32 mode = d_021F6384;
    if (mode != 0)
        func_021D4C58(mode);
}


void func_021EEAFC(void)
{
}


void func_021EEB00(BtlAdapter *adapter, u16 command, const void *src, u16 size)
{
    adapter->phase = 1;
    adapter->commandByte = command;
    adapter->packet.command = command;
    adapter->packet.size = size;
    func_02082D44(src, adapter->packet.data, size);
    adapter->peerData = 0;
    adapter->peerSize = 0;
    adapter->peerReady = 0;
}


int func_021EEB2C(BtlAdapter *adapter)
{
    switch (adapter->phase) {
    case 1:
        if (func_021EEB84(adapter) == 0)
            break;
        adapter->phase = 3;
    case 3:
        if (func_021EEBA4(adapter) == 0)
            break;
        adapter->phase = 4;
    case 4:
        return 1;
    }
    return 0;
}


const u8 *func_021EEB64(BtlAdapter *adapter, u32 *outSize)
{
    if (outSize != 0)
        *outSize = adapter->peerSize;
    return adapter->peerData;
}


void func_021EEB70(BtlAdapter *adapter)
{
    adapter->phase = 0;
    if (adapter->netId != 0)
        func_021D4C58(adapter->netId);
}


u32 func_021EEB84(BtlAdapter *adapter)
{
    struct BtlAdapterPacket *packet;

    if (adapter->netId != 0) {
        packet = &adapter->packet;
        return func_021D4B58(adapter->channel, packet, packet->size + 4);
    }
    return 1;
}


u32 func_021EEBA4(BtlAdapter *adapter)
{
    if (adapter->netId != 0) {
        if (func_021D4B98() != 0) {
            adapter->peerSize = func_021D4BD4(adapter->channel, &adapter->peerData);
            adapter->peerReady = 1;
            return 1;
        }
        return 0;
    }
    return adapter->peerReady;
}


void func_021EEBDC(BtlAdapter *adapter)
{
    adapter->packet.command = 0;
    adapter->packet.size = 4;
}


u8 func_021EEBE8(BtlAdapter *adapter)
{
    struct BtlAdapterPacket *packet;

    if (adapter->netId != 0) {
        if (func_021D4C60() != 0) {
            func_021D4C6C(&packet);
            return packet->command;
        }
        return 0;
    }
    if (adapter->peerReady == 0)
        return adapter->packet.command;
    return 0;
}


u16 func_021EEC20(BtlAdapter *adapter, u8 **outData)
{
    struct BtlAdapterPacket *packet;
    struct BtlAdapterPacket *received; /* second local keeps the register allocation */

    if (adapter->netId != 0) {
        func_021D4C6C(&packet);
        received = packet;
        *outData = received->data;
        return received->size;
    }
    *outData = adapter->packet.data;
    return adapter->packet.size;
}


u32 func_021EEC4C(BtlAdapter *adapter, const u8 *data, u32 size)
{
    if (adapter->netId != 0)
        return func_021D4C84(data, size);
    if (adapter->peerReady == 0) {
        adapter->peerData = data;
        adapter->peerSize = size;
        adapter->peerReady = 1;
    }
    return 1;
}


void func_021EEC78(struct BtlSystem *battle, u32 clientId, struct BtlPokeList *pokeList, u32 heapId)
{
    int i;

    d_021F6398.battle = battle;
    d_021F6398.pokeList = pokeList;
    d_021F6398.heapId = heapId;
    d_021F6398.clientId = clientId;
    d_021F6398.plainWording = func_021BA1A8(battle, 0x200);
    d_021F6398.useSpeciesName = 0;
    d_021F6398.wordSet = func_0201EC64(heapId);
    d_021F6398.msgBuf = func_020457B0(0x200 >> 1, heapId);
    for (i = 0; i < 8; i++) {
        d_021F6398.banks[i] = func_02045B38(0, 2, d_021F3990[i], heapId);
    }
}


void func_021EECD8(void)
{
    int i;

    func_0201ED04(d_021F6398.wordSet);
    func_02045808(d_021F6398.msgBuf);
    for (i = 0; i < 8; i++)
        func_02045C04(d_021F6398.banks[i]);
}


void func_021EED00(u8 pokeId, u32 slot)
{
    func_0201EEF4(d_021F6398.wordSet, slot, func_021D5864(func_021B9940(d_021F6398.pokeList, pokeId)));
}


void func_021EED24(u8 pokeId, u32 slot)
{
    func_0201EEF4(d_021F6398.wordSet, slot, func_021D5844(func_021B9940(d_021F6398.pokeList, pokeId)));
}


void func_021EED48(u8 pokeId, u8 slot)
{
    func_0201EE84(d_021F6398.wordSet, slot, func_021D5864(func_021B9940(d_021F6398.pokeList, pokeId)));
}


void func_021EED6C(struct WordSet *wordSet, u8 slot, u8 clientId)
{
    func_0201F0F8(wordSet, slot, (u8)func_021BA020(d_021F6398.battle, clientId));
}


void func_021EED90(struct WordSet *wordSet, u8 slot, u8 clientId)
{
    u32 trainerClass;
    int trainerId;
    const void *trainerData;

    if (clientId != 4) {
        if (func_021B9F70(d_021F6398.battle, clientId) != 0) {
            if (func_021B86B8(d_021F6398.battle) == 1) {
                trainerId = func_021BA004(d_021F6398.battle, clientId);
                if (trainerId != 0)
                    func_0201F134(wordSet, slot, trainerId);
            } else {
                trainerData = func_021B9FAC(d_021F6398.battle, clientId, &trainerClass);
                func_0201EE0C(wordSet, slot, trainerData, func_0202A3CC(trainerClass), 1, 2);
            }
        } else {
            func_0201F02C(wordSet, slot, func_021BA064(d_021F6398.battle, clientId));
        }
    } else {
        func_0201F02C(wordSet, slot, func_021BA080(d_021F6398.battle));
    }
}


/*
 * Variadic: copies argCount words into the eight-word table
 * BtlMsgState.args (zero-filling the rest), then hands the table
 * to func_021EEE80.
 */
void func_021EEE24(struct Strbuf *dest, u16 msgId, u32 argCount, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, argCount);
    for (i = 0; i < argCount; i++) {
        d_021F6398.args[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        d_021F6398.args[i] = 0;
    }
    func_021EEE80(dest, msgId, d_021F6398.args);
}


void func_021EEE80(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u32 i;

    for (i = 0; i < 27; i++) {
        if (msgId == d_021F39A0[i]) {
            if (func_021B8BD0(d_021F6398.battle, (u8)*args) == 0)
                msgId = msgId + 1;
            break;
        }
    }
    func_021EEEC8(dest, msgId, args);
}


void func_021EEEC8(struct Strbuf *dest, u32 msgId, u32 *args)
{
    func_02045CAC(d_021F6398.banks[0], msgId, d_021F6398.msgBuf);
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EEEF4(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (msgId == d_021F39D8[i].tag) {
            d_021F39D8[i].build(dest, msgId, args);
            return;
        }
    }
    func_021EF1CC(dest, msgId, args);
}


/*
 * Walks a message string for the first 0xF000 tag that func_0201D5CC calls a
 * word reference; the guard on text wraps the whole walk (two `return 0` tails).
 */
u16 *func_021EEF20(u16 *text, u32 *outGroup, u16 *outKind, u8 *outSlot)
{
    u16 endMark;
    u32 tagMark;

    if (text != 0) {
        endMark = func_02045A98();
        tagMark = func_0201D5C4();
        while (*text != endMark) {
            if (*text == tagMark) {
                if (func_0201D5CC(text) != 0) {
                    *outSlot = func_0201D670(text, 0);
                    *outGroup = func_0201D5F4(text);
                    *outKind = func_0201D658(text);
                    return func_0201D688(text);
                }
                text = func_0201D688(text);
            } else {
                text = text + 1;
            }
        }
        return 0;
    }
    return 0;
}


u8 func_021EEF98(struct Strbuf *text)
{
    u32 group;
    u16 kind;
    u8 slot;
    u16 *cursor;
    u8 count;

    cursor = STRBUF_GetChars(text);
    count = 0;
    if (cursor != 0) {
        do {
            cursor = func_021EEF20(cursor, &group, &kind, &slot);
            if (cursor != 0 && group == 1) {
                if (kind == 1 || kind == 2 || kind == 12)
                    count = count + 1;
            }
        } while (cursor != 0);
    }
    return count;
}


/*
 * Two passes over message tags: count removed slots, then install values.
 * A u8 kind local narrows before argument setup; const values schedules
 * the index shift ahead of the last outgoing argument store.
 */
void func_021EEFE0(struct Strbuf *text, const u32 *values, struct WordSet *wordSet)
{
    u16 endMark;
    u32 tagMark;
    u8 removedBefore[8];
    u16 *cursor;
    u32 i;
    u32 slot;
    u32 valueIndex;
    u8 group;
    u8 kind;
    endMark = func_02045A98();
    tagMark = func_0201D5C4();
    for (i = 0; i < 8; i++)
        removedBefore[i] = 0;
    cursor = STRBUF_GetChars(text);
    while (*cursor != endMark) {
        if (*cursor == tagMark) {
            if (func_0201D5CC(cursor)) {
                slot = func_0201D670(cursor, 0);
                if ((u8)func_0201D5F4(cursor) == 1 && func_0201D658(cursor) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removedBefore[i]++;
                }
            }
            cursor = func_0201D688(cursor);
        } else
            cursor++;
    }
    cursor = STRBUF_GetChars(text);
    while (*cursor != endMark) {
        if (*cursor == tagMark) {
            if (func_0201D5CC(cursor)) {
                slot = func_0201D670(cursor, 0);
                valueIndex = slot;
                group = func_0201D5F4(cursor);
                if (slot >= removedBefore[slot])
                    valueIndex = slot - removedBefore[slot];
                if (group == 2) {
                    kind = func_0201D658(cursor) + 1;
                    func_0201EFA4(wordSet, slot, values[valueIndex], kind, 0, 1);
                } else {
                    switch (func_0201D658(cursor)) {
                    case 14:
                        func_021EED6C(wordSet, slot, values[valueIndex]);
                        break;
                    case 0:
                        func_021EED90(wordSet, slot, values[valueIndex]);
                        break;
                    case 2:
                        if (d_021F6398.useSpeciesName == 0)
                            func_021EED00(values[valueIndex], slot);
                        else
                            func_021EED24(values[valueIndex], slot);
                        break;
                    case 12:
                        func_021EED24(values[valueIndex], slot);
                        break;
                    case 1:
                        func_021EED48(values[valueIndex], slot);
                        break;
                    case 3:
                        func_0201F020(wordSet, slot, values[valueIndex]);
                        break;
                    case 6:
                        func_0201EF8C(wordSet, slot, values[valueIndex]);
                        break;
                    case 7:
                        func_0201EF34(wordSet, slot, values[valueIndex]);
                        break;
                    case 9:
                        func_0201EF40(wordSet, slot, values[valueIndex]);
                        break;
                    case 15:
                        func_0201F020(wordSet, slot, values[valueIndex]);
                        break;
                    }
                }
            }
            cursor = func_0201D688(cursor);
        } else
            cursor++;
    }
}


void func_021EF1CC(struct Strbuf *dest, u16 msgId, u32 *args)
{
    func_02045CAC(d_021F6398.banks[1], msgId, d_021F6398.msgBuf);
    if (func_021EEF98(d_021F6398.msgBuf) == 2)
        func_021EF280(dest, msgId, args);
    else
        func_021EF204(dest, msgId, args);
}


/* Message offset (0, 1 or 2) for the side a client is on, 0 when wording is plain. */
static inline int BTL_MSG_GetSideVariant(u8 clientId)
{
    int sideVariant;
    if (d_021F6398.plainWording == 0 && func_021B8CE8(d_021F6398.battle, (u8)d_021F6398.clientId, func_021B8DDC(clientId))) {
        if (func_021B86B8(d_021F6398.battle) == 0 || func_021B86B8(d_021F6398.battle) == 4) sideVariant = 1;
        else sideVariant = 2;
    } else sideVariant = 0;
    return sideVariant;
}


void func_021EF204(struct Strbuf *dest, u32 msgId, u32 *args)
{
    int sideVariant;
    u8 clientId = *args;

    sideVariant = BTL_MSG_GetSideVariant(clientId);
    func_02045CAC(d_021F6398.banks[1], (u16)(msgId + sideVariant), d_021F6398.msgBuf);
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


/*
 * lever: explicit msgId = msgId + variant avoids compound-assignment RHS narrowing.
 */
void func_021EF280(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u8 secondClient = args[1];
    int firstVariant = BTL_MSG_GetSideVariant(args[0]);
    switch (firstVariant) {
    case 0:
        msgId = msgId + BTL_MSG_GetSideVariant(secondClient);
        break;
    case 1:
        msgId += 3;
        goto second;
    case 2:
        msgId += 5;
    default:
second:
        if (firstVariant == BTL_MSG_GetSideVariant(secondClient)) msgId++;
        break;
    }
    func_02045CAC(d_021F6398.banks[1], msgId, d_021F6398.msgBuf);
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


/*
 * Twin of func_021EF460 (partial sum in a named local, sideVariant added last).
 */
void func_021EF3A4(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsA *args)
{
    u8 entryIndex;
    int tierSelect;
    int sideVariant;
    u8 clientId;
    u32 position;

    entryIndex = args->entry - 1;
    tierSelect = 0;
    if (args->tier >= 3)
        tierSelect = 2;
    if (args->tier == 2)
        tierSelect = 1;
    msgId = (u16)(msgId + (u16)(tierSelect * 0x15));
    clientId = args->clientId;
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    func_021EED00(args->clientId, 0);
    func_0201EF40(d_021F6398.wordSet, 1, args->value);
    position = msgId + entryIndex * 3;
    func_02045CAC(d_021F6398.banks[1], (u16)(position + sideVariant), d_021F6398.msgBuf);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


/*
 * Lever: the partial sum msgId + entryIndex * 3 is a named local (`position`)
 * and sideVariant is added last; written inline as
 * `msgId + entryIndex * 3 + sideVariant` the final add comes out with its
 * operands swapped (one byte).
 */
void func_021EF460(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsB *args)
{
    u8 entryIndex;
    int tierSelect;
    int sideVariant;
    u8 clientId;
    u32 position;

    entryIndex = args->entry - 1;
    tierSelect = 0;
    if (args->tier >= 3)
        tierSelect = 2;
    if (args->tier == 2)
        tierSelect = 1;
    msgId = (u16)(msgId + (u16)(tierSelect * 0x15));
    func_021EED00(args->clientId, 0);
    clientId = args->clientId;
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    position = msgId + entryIndex * 3;
    func_02045CAC(d_021F6398.banks[1], (u16)(position + sideVariant), d_021F6398.msgBuf);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF508(struct Strbuf *dest, int msgId, u32 *args)
{
    u8 entryIndex = args[1] - 1;
    int sideVariant;
    int position;
    u8 clientId;

    func_021EED00(args[0], 0);
    clientId = args[0];
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    position = msgId + entryIndex * 3;
    func_02045CAC(d_021F6398.banks[1], (u16)(position + sideVariant), d_021F6398.msgBuf);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF594(struct Strbuf *dest, u32 msgId, u32 *args)
{
    u8 clientId = args[0];
    int msgIndex;

    if (clientId != func_021B8FF4(d_021F6398.battle)) {
        if (func_021B9F70(d_021F6398.battle, clientId))
            msgIndex = 0x23;
        else
            msgIndex = 0x22;
    } else {
        msgIndex = 0x21;
    }
    func_02045CAC(d_021F6398.banks[0], msgIndex, d_021F6398.msgBuf);
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF5E8(struct Strbuf *dest, u8 clientId, u16 entry)
{
    int sideVariant;
    u16 base;

    sideVariant = BTL_MSG_GetSideVariant(clientId);
    func_021EED00(clientId, 0);
    base = entry * 3;
    func_02045CAC(d_021F6398.banks[2], (u16)(base + sideVariant), d_021F6398.msgBuf);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF664(struct Strbuf *dest, u16 entry, int alternate)
{
    u16 msgIndex;

    if (entry != 0) {
        msgIndex = (entry - 1) * 3;
        if (alternate == 0)
            msgIndex = msgIndex + 1;
        else
            msgIndex = msgIndex + 2;
        func_02045CAC(d_021F6398.banks[7], msgIndex, dest);
    }
}


void func_021EF694(struct Strbuf *dest, u32 msgId)
{
    func_02045CAC(d_021F6398.banks[3], msgId, dest);
}


void func_021EF6A8(struct Strbuf *dest, u32 msgId, u32 *args)
{
    func_021EF6B0(dest, msgId, args);
}


void func_021EF6B0(struct Strbuf *dest, u32 msgId, u32 *args)
{
    func_02045CAC(d_021F6398.banks[5], msgId, d_021F6398.msgBuf);
    d_021F6398.useSpeciesName = 1;
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    d_021F6398.useSpeciesName = 0;
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


/*
 * Tail-call stub (ldr r3,[pc]; bx r3) to func_021EF6F0; callee of func_021EA55C case 6.
 */
void func_021EF6E8(struct Strbuf *dest, u32 msgId, u32 *args)
{
    func_021EF6F0(dest, msgId, args);
}


/*
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that func_021EA55C calls.
 * Twin of func_021EF6B0 without the useSpeciesName stores, using the +0x28 slot.
 */
void func_021EF6F0(struct Strbuf *dest, u32 msgId, u32 *args)
{
    func_02045CAC(d_021F6398.banks[6], msgId, d_021F6398.msgBuf);
    func_021EEFE0(d_021F6398.msgBuf, args, d_021F6398.wordSet);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF71C(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5)
{
    func_02045CAC(d_021F6398.banks[3], 0x10, d_021F6398.msgBuf);
    func_0201EFA4(d_021F6398.wordSet, 0, ball0, 2, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 1, ball1, 2, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 2, ball2, 2, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 3, ball3, 2, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 4, ball4, 2, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 5, ball5, 2, 0, 1);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}


void func_021EF7AC(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5)
{
    func_02045CAC(d_021F6398.banks[3], 0x11, d_021F6398.msgBuf);
    func_0201EFA4(d_021F6398.wordSet, 0, ball0, 3, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 1, ball1, 3, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 2, ball2, 3, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 3, ball3, 3, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 4, ball4, 3, 0, 1);
    func_0201EFA4(d_021F6398.wordSet, 5, ball5, 3, 0, 1);
    func_0201F250(d_021F6398.wordSet, dest, d_021F6398.msgBuf);
}
