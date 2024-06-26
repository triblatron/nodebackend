graph=
{
    nodes=
    {
        {
            id=0,
            name="foo1",
            class="FooTyped",
            category="CATEGORY_SINK",
            ports=
            {
                {
                    name="in1",
                    class="TypedPort<double>",
                    direction="DIR_IN",
                    type="TYPE_DOUBLE",
                    value=2.0,
                }
            }
        },
        {
            id=0,
            name="bar1",
            class="BarTyped",
            category="CATEGORY_SOURCE",
            ports=
            {
                {
                    name="out1",
                    class="TypedPort<double>",
                    direction="DIR_OUT",
                    type="TYPE_DOUBLE",
                    value=2.0,                    
                }
            }
        }
    },
    signalpaths=
    {
        {
            sourceNode="bar1",
            sourcePort=0,
            destNode="foo1",
            destPort=0
        },
    }
}
