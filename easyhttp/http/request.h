/**
 * @file request.h
 * @brief http请求
 * @author chxuan, 787280310@qq.com
 * @version 1.0.0
 * @date 2018-01-07
 */
#pragma once

#include <vector>
#include "header.h"

namespace easyhttp 
{

struct param
{
    std::string name;
    std::string value;
}; 

struct request
{
    inline std::string get_param_value(const std::string& name)
    {
        for (auto& param : params)
        {
            if (param.name == name)
            {
                return param.value;
            }
        }

        return "";
    }

    inline std::string get_header_value(const std::string& name)
    {
        for (auto& header : headers)
        {
            if (header.name == name)
            {
                return header.value;
            }
        }

        return "";
    }

    std::string method;
    std::string uri;
    std::vector<param> params;
    int http_main_version;
    int http_sub_version;
    std::vector<header> headers;
    std::string body;
};

}
