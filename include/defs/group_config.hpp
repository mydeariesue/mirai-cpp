#pragma once
#ifndef mirai_cpp_defs_group_config_hpp_H_
#define mirai_cpp_defs_group_config_hpp_H_

#include <nlohmann/json.hpp>
#include "serializable.hpp"

namespace Cyan
{
	// Ⱥ����
	class GroupConfig : public ISerializable
	{
	public:
		string Name;
		string Announcement;
		bool ConfessTalk;
		bool AllowMemberInvite;
		bool AutoApprove;
		bool AnonymousChat;
		virtual bool Set(const json& j) override
		{
			Name = j["name"].get<string>();
			Announcement = j["announcement"].get<string>();
			ConfessTalk = j["confessTalk"].get<bool>();
			AllowMemberInvite = j["allowMemberInvite"].get<bool>();
			AutoApprove = j["autoApprove"].get<bool>();
			AnonymousChat = j["anonymousChat"].get<bool>();
			return true;
		}
		virtual json ToJson() const override
		{
			json j = json::object();
			j["name"] = Name;
			j["announcement"] = Announcement;
			j["confessTalk"] = ConfessTalk;
			j["allowMemberInvite"] = AllowMemberInvite;
			j["autoApprove"] = AutoApprove;
			j["anonymousChat"] = AnonymousChat;
			return j;
		}
	};

}

#endif // !mirai_cpp_defs_group_config_hpp_H_