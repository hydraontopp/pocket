#region

using Pocket.ClientBase;
using Pocket.Modules.Extra;

#endregion

namespace Pocket.Modules
{
    internal class AirJump : Module
    {
        public AirJump() : base("AirJump", (char)0x07, "Movement")
        {
            addBypass(new BypassBox(new string[] { "onGround: True", "onGround: False" }));
        }

        public override void OnTick()
        {
            if (!Game.isNull)
                Game.onGround = (bypasses[0].curIndex != 0);
        }
    }
}