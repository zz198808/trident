/***************************************************************************
 *
 * Copyright (c) 2013 The Trident Authors. All Rights Reserved
 *
 * 
 * CreateTime: 2013-02-22
 *
 * Description:
 *
 **************************************************************************/

#include <trident/pbrpc.h>
#include "trident/sample/timeout_sample/sleep_service.pb.h"

int main(int /*argc*/, char** /*argv*/)
{
    TRIDENT_SET_LOG_LEVEL(NOTICE);

    // Define an rpc client.
    trident::RpcClientOptions client_options;
    trident::RpcClient rpc_client(client_options);

    // Define an rpc channel.
    trident::RpcChannelOptions channel_options;
    trident::RpcChannel rpc_channel(&rpc_client, "127.0.0.1:12321", channel_options);

    // Prepare objects.
    trident::RpcController* cntl = new trident::RpcController();
    trident::test::SleepRequest* request =
        new trident::test::SleepRequest();
    trident::test::SleepResponse* response =
        new trident::test::SleepResponse();
    trident::test::SleepServer_Stub* stub =
        new trident::test::SleepServer_Stub(&rpc_channel);

    // Call 1
    SLOG(NOTICE, "----------- Call 1 ---------------------------------------");
    SLOG(NOTICE, "Sync call SleepWithServiceTimeout(), timeout is 2 seconds.");
    SLOG(NOTICE, "Sleep for 1 seconds.");
    cntl->Reset();
    request->set_sleep_time(1);
    stub->SleepWithServiceTimeout(cntl, request, response, NULL);
    SLOG(NOTICE, "Actual timeout is %lld milli-seconds.", cntl->Timeout());
    if (cntl->Failed()) {
        SLOG(ERROR, "Failed: %s", cntl->ErrorText().c_str());
    }
    else {
        SLOG(NOTICE, "Succeed: %s", response->message().c_str());
    }

    // Call 2
    SLOG(NOTICE, "----------- Call 2 ---------------------------------------");
    SLOG(NOTICE, "Sync call SleepWithServiceTimeout(), timeout is 2 seconds.");
    SLOG(NOTICE, "Sleep for 3 seconds.");
    cntl->Reset();
    request->set_sleep_time(3);
    stub->SleepWithServiceTimeout(cntl, request, response, NULL);
    SLOG(NOTICE, "Actual timeout is %lld milli-seconds.", cntl->Timeout());
    if (cntl->Failed()) {
        SLOG(ERROR, "Failed: %s", cntl->ErrorText().c_str());
    }
    else {
        SLOG(NOTICE, "Succeed: %s", response->message().c_str());
    }

    // Call 3
    SLOG(NOTICE, "----------- Call 3 ---------------------------------------");
    SLOG(NOTICE, "Sync call SleepWithMethodTimeout(), timeout is 4 seconds.");
    SLOG(NOTICE, "Sleep for 3 seconds.");
    cntl->Reset();
    request->set_sleep_time(3);
    stub->SleepWithMethodTimeout(cntl, request, response, NULL);
    SLOG(NOTICE, "Actual timeout is %lld milli-seconds.", cntl->Timeout());
    if (cntl->Failed()) {
        SLOG(ERROR, "Failed: %s", cntl->ErrorText().c_str());
    }
    else {
        SLOG(NOTICE, "Succeed: %s", response->message().c_str());
    }

    // Call 4
    SLOG(NOTICE, "----------- Call 4 ---------------------------------------");
    SLOG(NOTICE, "Sync call SleepWithMethodTimeout(), timeout is 4 seconds.");
    SLOG(NOTICE, "Sleep for 5 seconds.");
    cntl->Reset();
    request->set_sleep_time(5);
    stub->SleepWithMethodTimeout(cntl, request, response, NULL);
    SLOG(NOTICE, "Actual timeout is %lld milli-seconds.", cntl->Timeout());
    if (cntl->Failed()) {
        SLOG(ERROR, "Failed: %s", cntl->ErrorText().c_str());
    }
    else {
        SLOG(NOTICE, "Succeed: %s", response->message().c_str());
    }

    // Call 5
    SLOG(NOTICE, "----------- Call 5 ---------------------------------------");
    SLOG(NOTICE, "Sync call SleepWithMethodTimeout(), timeout is 4 seconds.");
    SLOG(NOTICE, "Set timeout of RpcController to 1 seconds.");
    SLOG(NOTICE, "Sleep for 3 seconds.");
    cntl->Reset();
    cntl->SetTimeout(1000);
    request->set_sleep_time(3);
    stub->SleepWithMethodTimeout(cntl, request, response, NULL);
    SLOG(NOTICE, "Actual timeout is %lld milli-seconds.", cntl->Timeout());
    if (cntl->Failed()) {
        SLOG(ERROR, "Failed: %s", cntl->ErrorText().c_str());
    }
    else {
        SLOG(NOTICE, "Succeed: %s", response->message().c_str());
    }

    delete cntl;
    delete request;
    delete response;
    delete stub;
    return EXIT_SUCCESS;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
