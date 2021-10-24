#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"

class BlockSource {};

class Actor {
private: // Variables
	char pad_0x0000[0x138]; //0x0000
public:
	Vector2 CameraRots; //0x0138
	Vector2 CameraRots2; //0x0140
private:
	char pad_0x0148[0x10]; //0x0148
public:
	Vector3 EyeHeight; //0x0158
private:
	char pad_0x0164[0x70]; //0x0164
public: // 0x1BC
	float fallDistance; //0x01D4
	unsigned char onGround; //0x01D8
	unsigned char onGround2; //0x01D9
	unsigned char WalkingIntoBlock;
	unsigned char onGround3; //0x01DB
	unsigned char WalkingIntoBlock2; //0x01DC
private:
	char pad_0x01DD[0x5B]; //0x01DD
public:
	float StepHeight; //0x0238
private:
	char pad_0x023C[0x4]; //0x023C
public:
	float WalkDistance; //0x0240
	float WalkDistance1; //0x0244
	float MoveDistance; //0x0248
private:
	char pad_0x024C[0xC]; //0x024C
public:
	float MoveDistanceExact; //0x0258
private:
	char pad_0x025C[0x1]; //0x025C
public:
	unsigned char IsInWater; //0x025D
private:
	char pad_0x025E[0x4A]; //0x025E
public:
	__int32 TicksPast; //0x02A8
private:
	char pad_0x02AC[0x1D]; //0x02AC
public:
	unsigned char IsInLava; //0x02C9
private:
	char pad_0x02CA[0x7A]; //0x02CA
public:
	float SpeedCalc; //0x0344
	__int32 SpeedCalc2; //0x0348
	float MoveTick; //0x034C
private:
	char pad_0x0350[0x10]; //0x0350
public:
	BlockSource* blockSource; //0x0360
	Dimension* dimension; //0x0368
	Level* level; //0x0370
private:
	char pad_0x0378[0x88]; //0x0378
public:
	char EntityType[64]; //0xAE3E8838
private:
	char pad_0x0440[0x80]; //0x0440
public:
	AABB Position; //0x04C0
	Vector2 Hitbox; //0x04D8
	Vector3 currentPos; //0x04E0
	Vector3 lastPos; //0x04E0 + 12
	Vector3 Velocity; //0x04F8
	Vector3 Velocity2; //0x0504

public: // Functions
	void SetPos(Vector3 v) {
		this->Position.lower.x = v.x;
		this->Position.lower.y = v.y;
		this->Position.lower.z = v.z;

		this->Position.upper.x = v.x + 0.6f;
		this->Position.upper.y = v.y + 1.8f;
		this->Position.upper.z = v.z + 0.6f;
	};

	void SetFieldOfView(float v) {
		*(float*)((uintptr_t)(this) + 0x1058) = v;
	}
};