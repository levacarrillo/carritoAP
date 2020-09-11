// Generated by gencpp from file simple_move/SimpleMove.msg
// DO NOT EDIT!


#ifndef SIMPLE_MOVE_MESSAGE_SIMPLEMOVE_H
#define SIMPLE_MOVE_MESSAGE_SIMPLEMOVE_H

#include <ros/service_traits.h>


#include <simple_move/SimpleMoveRequest.h>
#include <simple_move/SimpleMoveResponse.h>


namespace simple_move
{

struct SimpleMove
{

typedef SimpleMoveRequest Request;
typedef SimpleMoveResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SimpleMove
} // namespace simple_move


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simple_move::SimpleMove > {
  static const char* value()
  {
    return "ec24e737ddaa2f1769f4aa74f864401d";
  }

  static const char* value(const ::simple_move::SimpleMove&) { return value(); }
};

template<>
struct DataType< ::simple_move::SimpleMove > {
  static const char* value()
  {
    return "simple_move/SimpleMove";
  }

  static const char* value(const ::simple_move::SimpleMove&) { return value(); }
};


// service_traits::MD5Sum< ::simple_move::SimpleMoveRequest> should match 
// service_traits::MD5Sum< ::simple_move::SimpleMove > 
template<>
struct MD5Sum< ::simple_move::SimpleMoveRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simple_move::SimpleMove >::value();
  }
  static const char* value(const ::simple_move::SimpleMoveRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simple_move::SimpleMoveRequest> should match 
// service_traits::DataType< ::simple_move::SimpleMove > 
template<>
struct DataType< ::simple_move::SimpleMoveRequest>
{
  static const char* value()
  {
    return DataType< ::simple_move::SimpleMove >::value();
  }
  static const char* value(const ::simple_move::SimpleMoveRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simple_move::SimpleMoveResponse> should match 
// service_traits::MD5Sum< ::simple_move::SimpleMove > 
template<>
struct MD5Sum< ::simple_move::SimpleMoveResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simple_move::SimpleMove >::value();
  }
  static const char* value(const ::simple_move::SimpleMoveResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simple_move::SimpleMoveResponse> should match 
// service_traits::DataType< ::simple_move::SimpleMove > 
template<>
struct DataType< ::simple_move::SimpleMoveResponse>
{
  static const char* value()
  {
    return DataType< ::simple_move::SimpleMove >::value();
  }
  static const char* value(const ::simple_move::SimpleMoveResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMPLE_MOVE_MESSAGE_SIMPLEMOVE_H
