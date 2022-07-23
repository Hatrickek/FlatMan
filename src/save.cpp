#include "save.h"
#include <FlatEngine.h>
namespace FlatMan {
	std::vector<PlayerComponent> savedPlayers;
	void Save::Init() {
		
		YAML::Node root;
		YAML::Comment("FlatMan save file.");
		for(const auto& player : savedPlayers) {
			root["Player"] = YAML::Node(YAML::NodeType::Map);
	
			YAML::Node wrnode = root["Player"];

			wrnode["name"] = player.m_Name;
			wrnode["score"] = player.m_Score;
		}
		
		YAML::Emitter out;
		out << root;

		std::ofstream fout("FlatManSave.save");
		fout << out.c_str();
	}
	void Save::SavePlayer(PlayerComponent& player){
		//savedPlayers.emplace_back(player);
	}
	void Save::ResetPlayerSave(){
		
	}
	void Save::LoadPlayers(){

	}
	void Save::Load(){
		
	}
}