/**
 * @file http_server.h
 * @brief http服务
 * @author chxuan, 787280310@qq.com
 * @version 1.0.0
 * @date 2018-01-06
 */
#pragma once

#include "easyhttp/net/tcp_server.h"
#include "router.h"

namespace easyhttp 
{

class http_server : public tcp_server
{
public:
    http_server(const std::string& host, int ios_threads = 4, int work_threads = 4);
    virtual ~http_server();

    virtual bool run();
    virtual void stop();
    void route(const std::string& uri, const request_handler& func);

protected:
    virtual void deal_request(const std::shared_ptr<request>& req, const std::shared_ptr<response>& res);

private:
    int work_threads_;
    router router_;
};

}
