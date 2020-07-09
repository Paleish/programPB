// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cliReq.proto

#ifndef PROTOBUF_cliReq_2eproto__INCLUDED
#define PROTOBUF_cliReq_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "lsEnum.pb.h"
#include "gameProto.pb.h"
// @@protoc_insertion_point(includes)
namespace lspb {
class CliReq;
class CliReqDefaultTypeInternal;
extern CliReqDefaultTypeInternal _CliReq_default_instance_;
}  // namespace lspb

namespace lspb {

namespace protobuf_cliReq_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_cliReq_2eproto

enum ClientMsgType {
  errorClientType = 0,
  cliEnterGame = 101,
  ClientMsgType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ClientMsgType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ClientMsgType_IsValid(int value);
const ClientMsgType ClientMsgType_MIN = errorClientType;
const ClientMsgType ClientMsgType_MAX = cliEnterGame;
const int ClientMsgType_ARRAYSIZE = ClientMsgType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientMsgType_descriptor();
inline const ::std::string& ClientMsgType_Name(ClientMsgType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientMsgType_descriptor(), value);
}
inline bool ClientMsgType_Parse(
    const ::std::string& name, ClientMsgType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientMsgType>(
    ClientMsgType_descriptor(), name, value);
}
// ===================================================================

class CliReq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lspb.CliReq) */ {
 public:
  CliReq();
  virtual ~CliReq();

  CliReq(const CliReq& from);

  inline CliReq& operator=(const CliReq& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CliReq(CliReq&& from) noexcept
    : CliReq() {
    *this = ::std::move(from);
  }

  inline CliReq& operator=(CliReq&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CliReq& default_instance();

  static inline const CliReq* internal_default_instance() {
    return reinterpret_cast<const CliReq*>(
               &_CliReq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CliReq* other);
  friend void swap(CliReq& a, CliReq& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CliReq* New() const PROTOBUF_FINAL { return New(NULL); }

  CliReq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CliReq& from);
  void MergeFrom(const CliReq& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CliReq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .lspb.CliEnterGame cliEnterGame = 4;
  bool has_clientergame() const;
  void clear_clientergame();
  static const int kCliEnterGameFieldNumber = 4;
  const ::lspb::CliEnterGame& clientergame() const;
  ::lspb::CliEnterGame* mutable_clientergame();
  ::lspb::CliEnterGame* release_clientergame();
  void set_allocated_clientergame(::lspb::CliEnterGame* clientergame);

  // int32 userId = 1;
  void clear_userid();
  static const int kUserIdFieldNumber = 1;
  ::google::protobuf::int32 userid() const;
  void set_userid(::google::protobuf::int32 value);

  // .lspb.ModuleId moduleId = 2;
  void clear_moduleid();
  static const int kModuleIdFieldNumber = 2;
  ::lspb::ModuleId moduleid() const;
  void set_moduleid(::lspb::ModuleId value);

  // .lspb.ClientMsgType methodId = 3;
  void clear_methodid();
  static const int kMethodIdFieldNumber = 3;
  ::lspb::ClientMsgType methodid() const;
  void set_methodid(::lspb::ClientMsgType value);

  // @@protoc_insertion_point(class_scope:lspb.CliReq)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::lspb::CliEnterGame* clientergame_;
  ::google::protobuf::int32 userid_;
  int moduleid_;
  int methodid_;
  mutable int _cached_size_;
  friend struct protobuf_cliReq_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CliReq

// int32 userId = 1;
inline void CliReq::clear_userid() {
  userid_ = 0;
}
inline ::google::protobuf::int32 CliReq::userid() const {
  // @@protoc_insertion_point(field_get:lspb.CliReq.userId)
  return userid_;
}
inline void CliReq::set_userid(::google::protobuf::int32 value) {
  
  userid_ = value;
  // @@protoc_insertion_point(field_set:lspb.CliReq.userId)
}

// .lspb.ModuleId moduleId = 2;
inline void CliReq::clear_moduleid() {
  moduleid_ = 0;
}
inline ::lspb::ModuleId CliReq::moduleid() const {
  // @@protoc_insertion_point(field_get:lspb.CliReq.moduleId)
  return static_cast< ::lspb::ModuleId >(moduleid_);
}
inline void CliReq::set_moduleid(::lspb::ModuleId value) {
  
  moduleid_ = value;
  // @@protoc_insertion_point(field_set:lspb.CliReq.moduleId)
}

// .lspb.ClientMsgType methodId = 3;
inline void CliReq::clear_methodid() {
  methodid_ = 0;
}
inline ::lspb::ClientMsgType CliReq::methodid() const {
  // @@protoc_insertion_point(field_get:lspb.CliReq.methodId)
  return static_cast< ::lspb::ClientMsgType >(methodid_);
}
inline void CliReq::set_methodid(::lspb::ClientMsgType value) {
  
  methodid_ = value;
  // @@protoc_insertion_point(field_set:lspb.CliReq.methodId)
}

// .lspb.CliEnterGame cliEnterGame = 4;
inline bool CliReq::has_clientergame() const {
  return this != internal_default_instance() && clientergame_ != NULL;
}
inline void CliReq::clear_clientergame() {
  if (GetArenaNoVirtual() == NULL && clientergame_ != NULL) delete clientergame_;
  clientergame_ = NULL;
}
inline const ::lspb::CliEnterGame& CliReq::clientergame() const {
  const ::lspb::CliEnterGame* p = clientergame_;
  // @@protoc_insertion_point(field_get:lspb.CliReq.cliEnterGame)
  return p != NULL ? *p : *reinterpret_cast<const ::lspb::CliEnterGame*>(
      &::lspb::_CliEnterGame_default_instance_);
}
inline ::lspb::CliEnterGame* CliReq::mutable_clientergame() {
  
  if (clientergame_ == NULL) {
    clientergame_ = new ::lspb::CliEnterGame;
  }
  // @@protoc_insertion_point(field_mutable:lspb.CliReq.cliEnterGame)
  return clientergame_;
}
inline ::lspb::CliEnterGame* CliReq::release_clientergame() {
  // @@protoc_insertion_point(field_release:lspb.CliReq.cliEnterGame)
  
  ::lspb::CliEnterGame* temp = clientergame_;
  clientergame_ = NULL;
  return temp;
}
inline void CliReq::set_allocated_clientergame(::lspb::CliEnterGame* clientergame) {
  delete clientergame_;
  clientergame_ = clientergame;
  if (clientergame) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:lspb.CliReq.cliEnterGame)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace lspb

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::lspb::ClientMsgType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::lspb::ClientMsgType>() {
  return ::lspb::ClientMsgType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cliReq_2eproto__INCLUDED