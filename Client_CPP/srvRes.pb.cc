// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: srvRes.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "srvRes.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace lspb {
class SrvResDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<SrvRes>
     _instance;
} _SrvRes_default_instance_;

namespace protobuf_srvRes_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SrvRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SrvRes, methodid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SrvRes, result_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SrvRes, errstr_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SrvRes, srventergame_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(SrvRes)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_SrvRes_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "srvRes.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::lspb::protobuf_lsEnum_2eproto::InitDefaults();
  ::lspb::protobuf_gameProto_2eproto::InitDefaults();
  _SrvRes_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_SrvRes_default_instance_);_SrvRes_default_instance_._instance.get_mutable()->srventergame_ = const_cast< ::lspb::SrvEnterGame*>(
      ::lspb::SrvEnterGame::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\014srvRes.proto\022\004lspb\032\014lsEnum.proto\032\017game"
      "Proto.proto\"\204\001\n\006SrvRes\022\"\n\010methodId\030\001 \001(\016"
      "2\020.lspb.SrvMsgType\022\034\n\006result\030\002 \001(\0162\014.lsp"
      "b.Result\022\016\n\006errStr\030\003 \001(\t\022(\n\014srvEnterGame"
      "\030\004 \001(\0132\022.lspb.SrvEnterGame*6\n\nSrvMsgType"
      "\022\023\n\017errorClientType\020\000\022\023\n\017serverEnterGame"
      "\020eB\022\n\020org.bro.lssrv.pbb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 270);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "srvRes.proto", &protobuf_RegisterTypes);
  ::lspb::protobuf_lsEnum_2eproto::AddDescriptors();
  ::lspb::protobuf_gameProto_2eproto::AddDescriptors();
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_srvRes_2eproto

const ::google::protobuf::EnumDescriptor* SrvMsgType_descriptor() {
  protobuf_srvRes_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_srvRes_2eproto::file_level_enum_descriptors[0];
}
bool SrvMsgType_IsValid(int value) {
  switch (value) {
    case 0:
    case 101:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SrvRes::kMethodIdFieldNumber;
const int SrvRes::kResultFieldNumber;
const int SrvRes::kErrStrFieldNumber;
const int SrvRes::kSrvEnterGameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SrvRes::SrvRes()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_srvRes_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:lspb.SrvRes)
}
SrvRes::SrvRes(const SrvRes& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  errstr_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.errstr().size() > 0) {
    errstr_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.errstr_);
  }
  if (from.has_srventergame()) {
    srventergame_ = new ::lspb::SrvEnterGame(*from.srventergame_);
  } else {
    srventergame_ = NULL;
  }
  ::memcpy(&methodid_, &from.methodid_,
    static_cast<size_t>(reinterpret_cast<char*>(&result_) -
    reinterpret_cast<char*>(&methodid_)) + sizeof(result_));
  // @@protoc_insertion_point(copy_constructor:lspb.SrvRes)
}

void SrvRes::SharedCtor() {
  errstr_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&srventergame_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&result_) -
      reinterpret_cast<char*>(&srventergame_)) + sizeof(result_));
  _cached_size_ = 0;
}

SrvRes::~SrvRes() {
  // @@protoc_insertion_point(destructor:lspb.SrvRes)
  SharedDtor();
}

void SrvRes::SharedDtor() {
  errstr_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete srventergame_;
}

void SrvRes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SrvRes::descriptor() {
  protobuf_srvRes_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_srvRes_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SrvRes& SrvRes::default_instance() {
  protobuf_srvRes_2eproto::InitDefaults();
  return *internal_default_instance();
}

SrvRes* SrvRes::New(::google::protobuf::Arena* arena) const {
  SrvRes* n = new SrvRes;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SrvRes::Clear() {
// @@protoc_insertion_point(message_clear_start:lspb.SrvRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errstr_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && srventergame_ != NULL) {
    delete srventergame_;
  }
  srventergame_ = NULL;
  ::memset(&methodid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&result_) -
      reinterpret_cast<char*>(&methodid_)) + sizeof(result_));
  _internal_metadata_.Clear();
}

bool SrvRes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:lspb.SrvRes)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .lspb.SrvMsgType methodId = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_methodid(static_cast< ::lspb::SrvMsgType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .lspb.Result result = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_result(static_cast< ::lspb::Result >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string errStr = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_errstr()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->errstr().data(), static_cast<int>(this->errstr().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "lspb.SrvRes.errStr"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .lspb.SrvEnterGame srvEnterGame = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_srventergame()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:lspb.SrvRes)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:lspb.SrvRes)
  return false;
#undef DO_
}

void SrvRes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:lspb.SrvRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .lspb.SrvMsgType methodId = 1;
  if (this->methodid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->methodid(), output);
  }

  // .lspb.Result result = 2;
  if (this->result() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->result(), output);
  }

  // string errStr = 3;
  if (this->errstr().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->errstr().data(), static_cast<int>(this->errstr().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "lspb.SrvRes.errStr");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->errstr(), output);
  }

  // .lspb.SrvEnterGame srvEnterGame = 4;
  if (this->has_srventergame()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, *this->srventergame_, output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:lspb.SrvRes)
}

::google::protobuf::uint8* SrvRes::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:lspb.SrvRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .lspb.SrvMsgType methodId = 1;
  if (this->methodid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->methodid(), target);
  }

  // .lspb.Result result = 2;
  if (this->result() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->result(), target);
  }

  // string errStr = 3;
  if (this->errstr().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->errstr().data(), static_cast<int>(this->errstr().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "lspb.SrvRes.errStr");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->errstr(), target);
  }

  // .lspb.SrvEnterGame srvEnterGame = 4;
  if (this->has_srventergame()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        4, *this->srventergame_, deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:lspb.SrvRes)
  return target;
}

size_t SrvRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:lspb.SrvRes)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string errStr = 3;
  if (this->errstr().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->errstr());
  }

  // .lspb.SrvEnterGame srvEnterGame = 4;
  if (this->has_srventergame()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->srventergame_);
  }

  // .lspb.SrvMsgType methodId = 1;
  if (this->methodid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->methodid());
  }

  // .lspb.Result result = 2;
  if (this->result() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->result());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SrvRes::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:lspb.SrvRes)
  GOOGLE_DCHECK_NE(&from, this);
  const SrvRes* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SrvRes>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:lspb.SrvRes)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:lspb.SrvRes)
    MergeFrom(*source);
  }
}

void SrvRes::MergeFrom(const SrvRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:lspb.SrvRes)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.errstr().size() > 0) {

    errstr_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.errstr_);
  }
  if (from.has_srventergame()) {
    mutable_srventergame()->::lspb::SrvEnterGame::MergeFrom(from.srventergame());
  }
  if (from.methodid() != 0) {
    set_methodid(from.methodid());
  }
  if (from.result() != 0) {
    set_result(from.result());
  }
}

void SrvRes::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:lspb.SrvRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SrvRes::CopyFrom(const SrvRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:lspb.SrvRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SrvRes::IsInitialized() const {
  return true;
}

void SrvRes::Swap(SrvRes* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SrvRes::InternalSwap(SrvRes* other) {
  using std::swap;
  errstr_.Swap(&other->errstr_);
  swap(srventergame_, other->srventergame_);
  swap(methodid_, other->methodid_);
  swap(result_, other->result_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SrvRes::GetMetadata() const {
  protobuf_srvRes_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_srvRes_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SrvRes

// .lspb.SrvMsgType methodId = 1;
void SrvRes::clear_methodid() {
  methodid_ = 0;
}
::lspb::SrvMsgType SrvRes::methodid() const {
  // @@protoc_insertion_point(field_get:lspb.SrvRes.methodId)
  return static_cast< ::lspb::SrvMsgType >(methodid_);
}
void SrvRes::set_methodid(::lspb::SrvMsgType value) {
  
  methodid_ = value;
  // @@protoc_insertion_point(field_set:lspb.SrvRes.methodId)
}

// .lspb.Result result = 2;
void SrvRes::clear_result() {
  result_ = 0;
}
::lspb::Result SrvRes::result() const {
  // @@protoc_insertion_point(field_get:lspb.SrvRes.result)
  return static_cast< ::lspb::Result >(result_);
}
void SrvRes::set_result(::lspb::Result value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:lspb.SrvRes.result)
}

// string errStr = 3;
void SrvRes::clear_errstr() {
  errstr_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& SrvRes::errstr() const {
  // @@protoc_insertion_point(field_get:lspb.SrvRes.errStr)
  return errstr_.GetNoArena();
}
void SrvRes::set_errstr(const ::std::string& value) {
  
  errstr_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:lspb.SrvRes.errStr)
}
#if LANG_CXX11
void SrvRes::set_errstr(::std::string&& value) {
  
  errstr_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:lspb.SrvRes.errStr)
}
#endif
void SrvRes::set_errstr(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  errstr_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:lspb.SrvRes.errStr)
}
void SrvRes::set_errstr(const char* value, size_t size) {
  
  errstr_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:lspb.SrvRes.errStr)
}
::std::string* SrvRes::mutable_errstr() {
  
  // @@protoc_insertion_point(field_mutable:lspb.SrvRes.errStr)
  return errstr_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* SrvRes::release_errstr() {
  // @@protoc_insertion_point(field_release:lspb.SrvRes.errStr)
  
  return errstr_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void SrvRes::set_allocated_errstr(::std::string* errstr) {
  if (errstr != NULL) {
    
  } else {
    
  }
  errstr_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), errstr);
  // @@protoc_insertion_point(field_set_allocated:lspb.SrvRes.errStr)
}

// .lspb.SrvEnterGame srvEnterGame = 4;
bool SrvRes::has_srventergame() const {
  return this != internal_default_instance() && srventergame_ != NULL;
}
void SrvRes::clear_srventergame() {
  if (GetArenaNoVirtual() == NULL && srventergame_ != NULL) delete srventergame_;
  srventergame_ = NULL;
}
const ::lspb::SrvEnterGame& SrvRes::srventergame() const {
  const ::lspb::SrvEnterGame* p = srventergame_;
  // @@protoc_insertion_point(field_get:lspb.SrvRes.srvEnterGame)
  return p != NULL ? *p : *reinterpret_cast<const ::lspb::SrvEnterGame*>(
      &::lspb::_SrvEnterGame_default_instance_);
}
::lspb::SrvEnterGame* SrvRes::mutable_srventergame() {
  
  if (srventergame_ == NULL) {
    srventergame_ = new ::lspb::SrvEnterGame;
  }
  // @@protoc_insertion_point(field_mutable:lspb.SrvRes.srvEnterGame)
  return srventergame_;
}
::lspb::SrvEnterGame* SrvRes::release_srventergame() {
  // @@protoc_insertion_point(field_release:lspb.SrvRes.srvEnterGame)
  
  ::lspb::SrvEnterGame* temp = srventergame_;
  srventergame_ = NULL;
  return temp;
}
void SrvRes::set_allocated_srventergame(::lspb::SrvEnterGame* srventergame) {
  delete srventergame_;
  srventergame_ = srventergame;
  if (srventergame) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:lspb.SrvRes.srvEnterGame)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace lspb

// @@protoc_insertion_point(global_scope)
