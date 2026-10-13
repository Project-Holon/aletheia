/*
 * file:     btl_server.c
 * unit:     yes
 * function: func_021BA9C8, func_021BAA94, func_021BAACC, func_021BAB10, func_021BAB40, func_021BAB5C, func_021BAB9C, func_021BABDC, func_021BABEC, func_021BABF4, func_021BAC04, func_021BACAC, func_021BAE60, func_021BAEF8, func_021BB040, func_021BB0A0, func_021BB0E0, func_021BB208, func_021BB280, func_021BB320, func_021BB368, func_021BB3B0, func_021BB3F8, func_021BB43C, func_021BB484, func_021BB4E0, func_021BB56C, func_021BB570, func_021BB5FC, func_021BB628, func_021BB650, func_021BB6A8, func_021BB718, func_021BB724, func_021BB768, func_021BB798, func_021BB7D0, func_021BB7FC, func_021BB828, func_021BB830, func_021BB840, func_021BB848, func_021BB85C, func_021BB878, func_021BB890, func_021BB8A8, func_021BB8B0, func_021BB8BC, func_021BB8DC, func_021BB908, func_021BB914, func_021BB920, func_021BB930, func_021BB964
 * address:  0x021BA9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): __FILE__ anchor 021BAA8C (d_021F3A60 "btl_server.c") used by the 0xcc4-byte BtlServer constructor 021BA9C8, which is the first function of the file.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_020307B0  0x020307B0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_021D787C  0x021D787C  thumb  ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_021EEA58  0x021EEA58  thumb  ov093
 *   func_02045808  0x02045808  arm
 *   func_021EEAE0  0x021EEAE0  thumb  ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021B85A8  0x021B85A8  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021B86DC  0x021B86DC  thumb  ov093
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021EE9B4  0x021EE9B4  thumb  ov093
 *   func_021EE9E4  0x021EE9E4  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021EE8B4 0x021EE8B4 thumb ov093
 *   func_021EE8D8 0x021EE8D8 thumb ov093
 *   func_021EE8F4  0x021EE8F4  thumb  ov093
 *   func_021EE96C  0x021EE96C  thumb  ov093
 *   func_021EEAE8  0x021EEAE8  thumb  ov093
 *   func_021EEB00  0x021EEB00  thumb  ov093
 *   func_021EEAFC  0x021EEAFC  thumb  ov093
 *   func_021EEB70 0x021EEB70 thumb ov093
 *   func_021EEB2C 0x021EEB2C thumb ov093
 *   func_021EEAD0 0x021EEAD0 thumb ov093
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   GAME_BEACON_SetPokeCapture 0x020271DC thumb
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_021B9120  0x021B9120  thumb  ov093
 *   func_021B916C  0x021B916C  thumb  ov093
 *   func_021B917C  0x021B917C  thumb  ov093
 *   func_021B91E4  0x021B91E4  thumb  ov093
 *   func_021B9234  0x021B9234  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021BA5D8  0x021BA5D8  thumb  ov093
 *   func_021BA618  0x021BA618  thumb  ov093
 *   func_021BB968  0x021BB968  thumb  ov093
 *   func_021BB9D0  0x021BB9D0  thumb  ov093
 *   func_021BBB48  0x021BBB48  thumb  ov093
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BBC34  0x021BBC34  thumb  ov093
 *   func_021BBC44  0x021BBC44  thumb  ov093
 *   func_021BBD20  0x021BBD20  thumb  ov093
 *   func_021BBD2C  0x021BBD2C  thumb  ov093
 *   func_021BBD80  0x021BBD80  thumb  ov093
 *   func_021BBD8C  0x021BBD8C  thumb  ov093
 *   func_021BC360  0x021BC360  thumb  ov093
 *   func_021BC390  0x021BC390  thumb  ov093
 *   func_021BC550  0x021BC550  thumb  ov093
 *   func_021BC55C  0x021BC55C  thumb  ov093
 *   func_021C84D8  0x021C84D8  thumb  ov093
 */
#include "btl_server_types.h"

extern u8 func_021D5440(u8 *p);
extern int func_021B86B8(struct BtlMain *main);
extern void *func_021D5844(void *m);
extern u32 func_02017E1C(void *p, u32 id, void *dst);
extern u32 func_021B8588(struct BtlMain *main);
extern u32 func_020307B0(void *p);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern void func_021D787C(void *);
extern void *func_02030734(u16, unsigned int, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern void func_02045808(void *strBuf);
extern void func_021EEAE0(void *p);
extern u8 func_021B86C0(struct BtlMain *main);
extern void *func_021EEB64(void *adapter, u32 *out);
extern int func_021B85A8(struct BtlMain *main);
extern u32 func_021D8454(Action *);
extern u8 *func_021EE9A4(u8 *p, unsigned int *out);
extern u16 func_021B86DC(struct BtlMain *main);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021EE9B4(u8 *, void *, int);
extern int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_021EE8B4(u8 *, int);
extern u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
extern void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
extern void *func_021EE96C(u8 *recorder, int stage, unsigned int *outSize);
extern void func_021EEAE8(void);
extern void func_021EEB00(void *adapter, int command, const void *data, int size);
extern void func_021EEAFC(void);
extern void func_021EEB70(void *adapter);
extern int func_021EEB2C(void *adapter);
extern void func_021EEAD0(void *adapter);
extern void GAME_BEACON_SetPokeLevelUp(void *strBuf);
extern void GAME_BEACON_SetPokeCapture(u16);
u8 func_021B8DE4(struct BtlMain *main, int clientId);
u8 func_021B8FF4(struct BtlMain *main);
u8 func_021B9114(struct BtlMain *main);
void func_021B9120(struct BtlMain *main, u8 n);
void func_021B916C(struct BtlMain *main,u32 x);
int func_021B917C(struct BtlMain *main);
void func_021B91E4(struct BtlMain *main, int add);
void func_021B9234(struct BtlMain *main);
u8 *func_021B9920(void *p, u32 i, u8 j);
void *func_021B9AEC(void *partyTable, int clientId);
u8 func_021B9B94(void *party);
u8 func_021B9B98(void *party);
void func_021BA1B4(struct BtlMain *main, int i);
int func_021BA5D8(struct BtlMain *main);
int func_021BA618(struct BtlMain *main);
BtlServer *func_021BA9C8(struct BtlMain *main, BtlServerRngState *rngState, void *partyTable, int flowParam, u16 heapId);
void func_021BAA94(BtlServer *server, void *adapter, u8 clientId, u8 battleSlots);
void func_021BAACC(BtlServer *server, int unused, int netId, int clientId, u8 battleSlots);
void func_021BAB10(BtlServer *server, u8 clientId, u8 battleSlots);
void func_021BAB40(BtlServer *server);
void func_021BAB5C(BtlServer *server);
int func_021BAB9C(BtlServer *server);
void func_021BABDC(BtlServer *server, BtlWordPair *out);
void func_021BABEC(BtlServer *server, BtlServerHandler handler);
void func_021BABF4(BtlServer *server);
int func_021BAC04(BtlServer *server, int *step);
int func_021BACAC(BtlServer *server, int *step);
int func_021BAE5C(BtlServer *server);
int func_021BAE60(BtlServer *server, int *step);
int func_021BAEF8(BtlServer *server, int *step);
int func_021BB040(BtlServer *server);
u32 func_021BB0A0(BtlServer *server);
int func_021BB0E0(BtlServer *server, int *step);
int func_021BB208(BtlServer *server, int *step);
int func_021BB280(BtlServer *server, int *step);
int func_021BB320(BtlServer *server, int *step);
int func_021BB368(BtlServer *server, int *step);
int func_021BB3B0(BtlServer *server, int *step);
int func_021BB3F8(BtlServer *server, int *step);
int func_021BB43C(BtlServer *server, int *step);
int func_021BB484(BtlServer *server, int *step);
void func_021BB4E0(BtlServer *server, void *src, int size);
void func_021BB56C(void *reply);
int func_021BB570(BtlServer *server, int stage, void *expected, u32 size);
int func_021BB5FC(BtlServer *server, int skipFlags);
int func_021BB628(BtlServer *server, int stage, int initArg);
void *func_021BB650(BtlServer *server, int stage, int initArg, unsigned int *outSize);
void func_021BB6A8(BtlServer *server);
void func_021BB718(BtlServer *server, int command);
void func_021BB724(BtlServer *server, int command, const void *data, int size);
void func_021BB768(BtlServer *server, int command, u32 clientIndex, const void *data, int size);
int func_021BB798(BtlServer *server);
void func_021BB7D0(const BtlServer *server);
void func_021BB7FC(const BtlServer *server);
void func_021BB828(BtlServerClient *client);
int func_021BB830(const BtlServerClient *client);
void func_021BB840(BtlServerClient *client, int clientId, void *adapter, int adapterBorrowed);
void func_021BB848(BtlServerClient *client, void *party, u8 battleSlots);
BtlServerClient *func_021BB85C(BtlServer *server, unsigned int index);
BtlServerClient *func_021BB878(BtlServer *server, u32 index);
int func_021BB890(BtlServer *server, u8 index);
u8 func_021BB8A8(BtlServerActionTable *table, u8 index);
Action func_021BB8B0(BtlServerActionTable *table, u8 row, u8 column);
void func_021BB8BC(BtlServer *server, u32 *pokeParam);
void func_021BB8DC(BtlServer *server, u32 *pokeParam);
void func_021BB908(BtlServer *server, int amount);
void func_021BB914(BtlServer *server);
void func_021BB920(BtlServer *server);
void func_021BB930(BtlServer *server, u32 clientId);
void *func_021BB964(BtlServer *server);
void *func_021BB968(BtlServer *server, struct BtlMain *main, void *partyTable, void *sendBuf, int flowParam, u16 heapId);
void func_021BB9D0(void *flow);
void func_021BBB48(void *flow);
int func_021BBB60(void *flow);
void func_021BBC34(void *flow);
int func_021BBC44(void *flow, void *reply);
void func_021BBD20(void *flow);
int func_021BBD2C(void *flow, void *reply);
void func_021BBD80(void *flow);
int func_021BBD8C(void *flow, void *reply);
int func_021BC360(void *flow);
int func_021BC390(void *flow);
BtlWordPair *func_021BC550(void *flow);
u8 func_021BC55C(void *flow);
int func_021C84D8(void *flow);
extern u8 d_021F3A60[];


BtlServer *func_021BA9C8(struct BtlMain *main, BtlServerRngState *rngState, void *partyTable, int flowParam, u16 heapId)
{
    BtlServer *server;
    int i;
    server = func_02030734(heapId, 0xcc4, 1, (const char *)d_021F3A60, 0xad);
    server->main = main;
    server->partyTable = partyTable;
    server->heapId = heapId;
    server->sendBuf = server->sendBufStorage;
    server->quitState = 0;
    server->flow = 0;
    server->changeCount = 0;
    server->changeLock = 0;
    server->flowParam = flowParam;
    server->rngState = *rngState;
    server->nameBuf = func_020457B0(0x20, heapId);
    func_021D787C(rngState);
    for (i = 0; i < 4; i++)
        func_021BB828(&server->clients[i]);
    server->flow = func_021BB968(server, server->main, server->partyTable, server->sendBufStorage, server->flowParam, server->heapId);
    server->finalData = func_021BC550(server->flow);
    func_021BABEC(server, func_021BAC04);
    return server;
}

void func_021BAA94(BtlServer *server, void *adapter, u8 clientId, u8 battleSlots)
{
    void *party;
    BtlServerClient *client;
    party = func_021B9AEC(server->partyTable, clientId);
    client = &server->clients[clientId];
    func_021BB840(client, clientId, adapter, 1);
    func_021BB848(client, party, battleSlots);
}

void func_021BAACC(BtlServer *server, int unused, int netId, int clientId, u8 battleSlots)
{
    void *party;
    void *adapter;
    BtlServerClient *client;

    party = func_021B9AEC(server->partyTable, clientId);
    adapter = func_021EEA58(netId, clientId, 1, server->heapId);
    client = &server->clients[clientId];
    func_021BB840(client, clientId, adapter, 0);
    func_021BB848(client, party, battleSlots);
}

void func_021BAB10(BtlServer *server, u8 clientId, u8 battleSlots)
{
    void *party;
    BtlServerClient *client;
    party = func_021B9AEC(server->partyTable, clientId);
    client = &server->clients[clientId];
    func_021BB840(client, clientId, 0, 0);
    func_021BB848(client, party, battleSlots);
}

void func_021BAB40(BtlServer *server)
{
    func_021BABEC(server, func_021BAC04);
    func_021BB7FC(server);
    func_021BB9D0(server->flow);
}

void func_021BAB5C(BtlServer *server)
{
    int i;
    func_02045808(server->nameBuf);
    func_021BBB48(server->flow);
    for (i = 0; i < 4; i++) {
        if (server->clients[i].clientId != 0xff && server->clients[i].adapter != 0 && server->clients[i].adapterBorrowed == 0)
            func_021EEAE0(server->clients[i].adapter);
    }
    func_020307B0(server);
}

int func_021BAB9C(BtlServer *server)
{
    if (server->quitState != 2) {
        BtlServerHandler handler = server->handler;
        if (handler(server, &server->step) != 0) {
            func_021BB724(server, 9, server->finalData, 8);
            server->quitState = 2;
        }
    } else {
        if (func_021BB798(server) != 0)
            return 1;
    }
    return 0;
}

void func_021BABDC(BtlServer *server, BtlWordPair *out)
{
    *out = *server->finalData;
}

void func_021BABEC(BtlServer *server, BtlServerHandler handler)
{
    server->handler = handler;
    server->step = 0;
}

void func_021BABF4(BtlServer *server)
{
    func_021BABEC(server, func_021BACAC);
}

int func_021BAC04(BtlServer *server, int *step)
{
    int *buf;

    switch (*step) {
    case 0:
        func_021BB718(server, 1);
        (*step)++;
    case 1:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            if (func_021B86B8(server->main) != 4) {
                func_021BB5FC(server, func_021BBB60(server->flow));
                (*step)++;
            } else {
                func_021BABEC(server, func_021BB280);
            }
        }
        break;
    case 2:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 3:
        buf = server->sendBuf;
        func_021BB724(server, 8, buf + 2, *buf);
        (*step)++;
        break;
    case 4:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            func_021BABF4(server);
        }
        break;
    }
    return 0;
}

/*
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is func_021BB0E0, the distinct case-1 callback;
 * reusing func_021BAEF8 there shortens the pool and cross-jumps the calls.
 */
int func_021BACAC(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        if (func_021BC390(server->flow)) {
            int *buf = server->sendBuf;
            func_021BB724(server, 8, buf + 2, *buf);
            (*step)++;
        } else
            *step += 2;
        break;
    case 1:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        func_021BB718(server, 3);
        (*step)++;
        break;
    case 3:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            if (func_021BA5D8(server->main)) {
                func_021BABEC(server, func_021BB208);
                break;
            }
            if (func_021BA618(server->main)) {
                func_021BABEC(server, func_021BB280);
                break;
            }
            func_021BB6A8(server);
            if (func_021BB628(server, 1, func_021BAE5C(server)))
                (*step)++;
            else
                *step += 2;
        }
        break;
    case 4:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 5:
        func_021BBC34(server->flow);
        func_021BB7D0(server);
        (*step)++;
    case 6:
        server->flowResult = func_021BBC44(server->flow, server->reply);
        if (func_021B86C0(server->main))
            func_021BB56C(server->reply);
        {
            int *buf = server->sendBuf;
            func_021BB724(server, 8, buf + 2, *buf);
        }
        (*step)++;
        break;
    case 7:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            switch (server->flowResult) {
            case 0:
                func_021BABF4(server);
                break;
            case 3:
                *step = 6;
                break;
            case 2:
                {
                    int competitor = func_021B86B8(server->main);
                    u32 rule = func_021B8588(server->main);
                    if (!competitor && !rule)
                        func_021BABEC(server, func_021BAE60);
                    else
                        func_021BABEC(server, func_021BAEF8);
                }
                break;
            case 1:
                func_021BABEC(server, func_021BB0E0);
                break;
            case 6:
                func_021B9120(server->main, func_021BC55C(server->flow));
                func_021BABEC(server, func_021BB280);
                return 0;
            case 4:
                func_021B916C(server->main, func_021C84D8(server->flow));
                func_021BABEC(server, func_021BB280);
                return 0;
            case 5:
            default:
                return 1;
            }
        }
        break;
    }
    return 0;
}

int func_021BAE5C(BtlServer *server)
{
    return 1;
}

int func_021BAE60(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB718(server, 7);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            u8 clientId = func_021B8FF4(server->main);
            int *buf;
            func_021BB7D0(server);
            if (*(u8 *)func_021EEB64(server->clients[clientId].adapter, 0) == 0) {
                func_021BABEC(server, func_021BAEF8);
            } else {
                server->flowResult = func_021BC360(server->flow);
                buf = server->sendBuf;
                func_021BB724(server, 8, buf + 2, *buf);
                (*step)++;
            }
        }
        break;
    case 2:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            if (server->flowResult != 0)
                return 1;
            func_021BABEC(server, func_021BAEF8);
        }
        break;
    }
    return 0;
}

/*
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 */
int func_021BAEF8(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 5, server->changeClients, server->changeCount);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server)) {
            if (func_021BB040(server)) {
                server->shiftPromptMon = func_021BB0A0(server);
                func_021BB768(server, 4, 0, &server->shiftPromptMon, 1);
            }
            (*step)++;
        }
        break;
    case 2:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            if (func_021BA618(server->main)) {
                func_021BABEC(server, func_021BB280);
                break;
            }
            func_021BB6A8(server);
            if (func_021BB628(server, 2, 0))
                (*step)++;
            else
                *step += 2;
        }
        break;
    case 3:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 4:
        func_021BB7D0(server);
        func_021BBD80(server->flow);
        (*step)++;
    case 5:
        server->flowResult = func_021BBD8C(server->flow, server->reply);
        {
            int *buf = server->sendBuf;
            func_021BB724(server, 8, buf + 2, *buf);
        }
        (*step)++;
        break;
    case 6:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            switch (server->flowResult) {
            case 2:
                *step = 0;
                break;
            case 3:
                *step = 5;
                break;
            case 4:
                func_021B916C(server->main, func_021C84D8(server->flow));
                func_021BABEC(server, func_021BB280);
                break;
            case 5:
                return 1;
            default:
                func_021BABF4(server);
                break;
            }
        }
        break;
    }
    return 0;
}

int func_021BB040(BtlServer *server)
{
    unsigned i;
    if (func_021B85A8(server->main) != 0 && server->changeCount != 0) {
        for (i = 0; i < server->changeCount; i++) {
            if (func_021B8DE4(server->main, server->changeClients[i]) == 0)
                return 0;
        }
        if (func_021B9B98(func_021B9AEC(server->partyTable, func_021B8FF4(server->main))) < 2)
            return 0;
        return 1;
    }
    return 0;
}

u32 func_021BB0A0(BtlServer *server)
{
    BtlServerClient *client = &server->clients[1];
    Action *action;
    if (func_021BB830(client) != 0) {
        action = func_021EEB64(client->adapter, 0);
        if (func_021D8454(action) == 3) {
            u8 *party = func_021B9920(server->partyTable, 1, action->small.move);
            return func_021D5440(party);
        }
    }
    return 0x1f;
}

int func_021BB0E0(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 6, server->changeClients, server->changeCount);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            if (func_021BA618(server->main)) {
                func_021BABEC(server, func_021BB280);
            } else {
                func_021BB6A8(server);
                if (func_021BB628(server, 3, 0)) (*step)++;
                else *step += 2;
            }
        }
        break;
    case 2:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 3:
        func_021BB7D0(server);
        func_021BBD20(server->flow);
        (*step)++;
    case 4: {
        int *buf;
        buf = server->sendBuf;
        buf[0] = 0;
        buf[1] = 0;
        server->flowResult = func_021BBD2C(server->flow, server->reply);
        buf = server->sendBuf;
        func_021BB724(server, 8, buf + 2, buf[0]);
        (*step)++;
        break;
    }
    case 5:
        if (func_021BB798(server)) {
            func_021BB7D0(server);
            switch (server->flowResult) {
            case 1: *step = 0; break;
            case 3: *step = 4; break;
            case 2: func_021BABEC(server, func_021BAEF8); break;
            case 4:
                func_021B916C(server->main, func_021C84D8(server->flow));
                func_021BABEC(server, func_021BB280);
                break;
            case 5: return 1;
            case 0:
            default: func_021BABF4(server); break;
            }
        }
        break;
    }
    return 0;
}

int func_021BB208(BtlServer *server, int *step)
{
    unsigned int size;
    switch (*step) {
    case 0: {
        u8 *packet = func_021EE9A4(server->recorder, &size);
        func_021BB724(server, 0xa, packet, size);
        (*step)++;
        break;
    }
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            func_021BB718(server, 0x10);
            (*step)++;
        }
        break;
    case 2:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            func_021B916C(server->main, func_021C84D8(server->flow));
            func_021BABEC(server, func_021BB280);
        }
        break;
    }
    return 0;
}

int func_021BB280(BtlServer *server, int *step)
{
    int result = func_021B917C(server->main);
    server->result.result = result;
    server->result.playerClientId = func_021B8FF4(server->main);
    switch (func_021B86B8(server->main)) {
    case 1:
        func_021BABEC(server, func_021BB43C);
        break;
    case 2:
        func_021BABEC(server, func_021BB484);
        break;
    case 3:
        func_021BABEC(server, func_021BB3F8);
        break;
    case 0:
        if (result == 1) {
            func_021BABEC(server, func_021BB368);
        } else if (result == 0 || result == 2) {
            func_021BABEC(server, func_021BB3B0);
        } else {
            func_021BABEC(server, func_021BB320);
        }
        break;
    default:
        if (result == 1) {
            GFL_USE_CancelChangeAndPlayBgm(func_021B86DC(server->main), 0xffff);
        }
        func_021BABEC(server, func_021BB320);
        break;
    }
    return 0;
}

int func_021BB320(BtlServer *server, int *step)
{
    switch (*step) {
    case 0: {
        int finished = 0;
        if (func_021B9114(server->main) == 0) {
            if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) finished = 1;
        } else {
            finished = 1;
        }
        if (finished != 0) {
            (*step)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}

int func_021BB368(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 0xe, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        func_021BABEC(server, func_021BB320);
        break;
    }
    return 0;
}

int func_021BB3B0(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 0xf, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        func_021BABEC(server, func_021BB320);
        break;
    }
    return 0;
}

int func_021BB3F8(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 0xd, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

int func_021BB43C(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 0xb, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        func_021BABEC(server, func_021BB320);
        break;
    }
    return 0;
}

int func_021BB484(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        func_021BB724(server, 0xc, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (func_021BB798(server) != 0) {
            func_021BB7D0(server);
            (*step)++;
        }
        break;
    case 2:
        if (func_021B86C0(server->main) == 0) {
            func_021BABEC(server, func_021BB320);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}

void func_021BB4E0(BtlServer *server, void *src, int size)
{
    u8 i;
    u8 clientId;
    u8 count;
    u32 index;
    u32 words[3];
    index = 0;
    for (i = 0; i < 4; i++)
        server->replyCount[i] = 0;
    func_021EE9B4(server->recorder, src, size);
    while (func_021EE9E4(server->recorder, &index, &clientId, &count, words) != 0) {
        for (i = 0; i < count; i++)
            server->reply[clientId].word[i].value = words[i];
        server->replyCount[clientId] = count;
    }
}

void func_021BB56C(void *reply)
{
}

int func_021BB570(BtlServer *server, int stage, void *expected, u32 size)
{
    u32 *buf = server->sendBuf;
    buf[0] = 0;
    buf[1] = 0;
    switch (stage) {
    case 4:
        func_021BBB60(server->flow);
        break;
    case 1:
        func_021BBC34(server->flow);
        func_021BBC44(server->flow, server->reply);
        break;
    case 2:
        func_021BBD80(server->flow);
        func_021BBD8C(server->flow, server->reply);
        break;
    case 3:
        func_021BBD20(server->flow);
        func_021BBD2C(server->flow, server->reply);
        break;
    }
    buf = server->sendBuf;
    if (buf[0] == size && func_0203EFC8((const u8 *)(buf + 2), expected, size) == 0)
        return 0;
    return 1;
}

int func_021BB5FC(BtlServer *server, int skipFlags)
{
    unsigned int size;
    u8 *packet;
    func_021EE8B4(server->recorder, 1);
    packet = func_021EE8D8(server->recorder, &size, skipFlags);
    func_021BB724(server, 10, packet, size);
    return 1;
}

/*
 * interface: func_021BB650's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &size in r3 and reads r0, so its extern preserves both.
 */
int func_021BB628(BtlServer *server, int stage, int initArg)
{
    unsigned int size;
    void *packet;
    packet = func_021BB650(server, stage, initArg, &size);
    if (packet != 0) {
        func_021BB724(server, 10, packet, size);
        return 1;
    }
    return 0;
}

void *func_021BB650(BtlServer *server, int stage, int initArg, unsigned int *outSize)
{
    u32 i;
    u32 header;
    func_021EE8B4(server->recorder, initArg);
    for (i = 0; i < 4; i++) {
        if (server->clients[i].clientId != 0xff) {
            const void *data = func_021EEB64(server->clients[i].adapter, &header);
            func_021EE8F4(server->recorder, i, data, (header << 22) >> 24);
        }
    }
    return func_021EE96C(server->recorder, stage, outSize);
}

/*
 * note 2026-10-05 (final push G6L5): closed by copying each word through a one-word struct
 *   (BtlServerWord, source cursor `BtlServerWord *src`, destination element type BtlServerWord, so
 *   `server->reply[i].word[j] = *src++;` is a struct assignment). The word-copy path creates the load before
 *   the destination address, which gives the walking source in r2 with j in r0, cnt in r1 and
 *   the load in r6. Plain `u32 *s` with `*s++` (every spelling) gave j=r1, cnt=r2, s=r3, load r0
 *   (51 bytes); indexed `s[j]` gave `ldr r6,[r2,r4]` (1 byte). Same shape in both lang c99 and c.
 */
void func_021BB6A8(BtlServer *server)
{
    u32 i;
    u32 j;
    u32 size;
    u32 count;
    BtlServerWord *src;
    BtlServerClient *client;
    for (i = 0; i < 4; i++) {
        client = &server->clients[i];
        server->replyCount[i] = 0;
        if (func_021BB830(client) != 0) {
            src = func_021EEB64(client->adapter, &size);
            count = size >> 2;
            for (j = 0; j < count; j++) {
                server->reply[i].word[j] = *src++;
                server->replyCount[i]++;
            }
        }
    }
}

void func_021BB718(BtlServer *server, int command)
{
    func_021BB724(server, command, 0, 0);
}

void func_021BB724(BtlServer *server, int command, const void *data, int size)
{
    int i;
    BtlServerClient *clients;
    func_021EEAE8();
    i = 0;
    clients = server->clients;
    for (; i < 4; i++) {
        if (func_021BB830(clients + i) != 0)
            func_021EEB00(server->clients[i].adapter, command, data, size);
    }
    func_021EEAFC();
}

void func_021BB768(BtlServer *server, int command, u32 clientIndex, const void *data, int size) {
    BtlServerClient *client;
    client = &server->clients[clientIndex];
    if (func_021BB830(client)) {
        func_021EEB70(client->adapter);
        func_021EEB00(client->adapter, command, data, size);
    }
}

int func_021BB798(BtlServer *server) {
    int allReceived;
    int i;
    BtlServerClient *clients;
    allReceived = 1; i = 0; clients = server->clients;
    for (; i < 4; i++) {
        if (func_021BB830(clients + i)) {
            if (!func_021EEB2C(server->clients[i].adapter)) allReceived = 0;
        }
    }
    return allReceived;
}

void func_021BB7D0(const BtlServer *server) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830(&server->clients[i])) func_021EEB70(server->clients[i].adapter);
    }
}

void func_021BB7FC(const BtlServer *server) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830(&server->clients[i])) func_021EEAD0(server->clients[i].adapter);
    }
}

/*
 * store constant 0xff at #0xb
 */
void func_021BB828(BtlServerClient *client)
{
    client->clientId = 0xff;
}

int func_021BB830(const BtlServerClient *client) { if (client->clientId != 255) return 1; return 0; }

void func_021BB840(BtlServerClient *client, int clientId, void *adapter, int adapterBorrowed)
{
    client->clientId = clientId;
    client->adapter = adapter;
    client->adapterBorrowed = adapterBorrowed;
}

void func_021BB848(BtlServerClient *client, void *party, u8 battleSlots) { client->party = party; client->partyCount = func_021B9B94(party); client->battleSlots = battleSlots; }

BtlServerClient *func_021BB85C(BtlServer *server, unsigned int index) { if (index < 4 && server->clients[index].clientId != 255) return &server->clients[index]; return 0; }

BtlServerClient *func_021BB878(BtlServer *server, u32 index) { if (server->clients[index].clientId != 255) return &server->clients[index]; return 0; }

int func_021BB890(BtlServer *server, u8 index) { if (index < 4) return func_021BB830(&server->clients[index]); return 0; }

/* 021BB8A8  adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0x30; ldrb r0, [r0]; bx lr.
 */
u8 func_021BB8A8(BtlServerActionTable *table, u8 index) { return table->value[index]; }

/* 021BB8B0  movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3;
 *           ldr r0,[r1,r0] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r3, #0xc; muls r3, r1, r3; lsls r1, r2, #2; adds r0, r0, r3; ldr r0, [r1, r0]; bx lr.
 */
Action func_021BB8B0(BtlServerActionTable *table, u8 row, u8 column)
{
    return table->action[row][column];
}

void func_021BB8BC(BtlServer *server, u32 *pokeParam) {
    func_02017E1C(func_021D5844(pokeParam),0x73,server->nameBuf);
    GAME_BEACON_SetPokeLevelUp(server->nameBuf);
}

/*
 * evidence: caller narrows func_02017E1C result to u16 before 020271DC.
 */
void func_021BB8DC(BtlServer *server, u32 *pokeParam) {
    GAME_BEACON_SetPokeCapture(func_02017E1C(func_021D5844(pokeParam),5,0));
    func_021BA1B4(server->main,7);
    func_021BA1B4(server->main,0x54);
}

void func_021BB908(BtlServer *server, int amount)
{
    func_021B91E4(server->main, amount);
}

/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 *
 * UNBLOCKED: func_021B9234 is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BB914(BtlServer *server)
{
    func_021B9234(server->main);
}

void func_021BB920(BtlServer *server) { server->changeCount = 0; server->changeLock = 0; }

/*
 * Lever: left-associated pointer addition p + count + 0xcb4 preserves
 * the base-plus-count computation before the incrementing byte store.
 */
void func_021BB930(BtlServer *server, u32 clientId)
{
    u32 i;
    u32 count = server->changeCount;
    for (i = 0; i < count; i++) {
        if (clientId == server->changeClients[i]) return;
    }
    server->changeCount++;
    server->changeClients[count] = clientId;
}

void *func_021BB964(BtlServer *server) { return server->flow; }
