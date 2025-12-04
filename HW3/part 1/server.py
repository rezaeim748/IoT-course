import aiocoap.resource as resource
import aiocoap
import asyncio

# DOC: https://aiocoap.readthedocs.io/en/latest/installation.html#installation-development
class AlarmResource(resource.Resource):
    """This resource supports the POST method.
    POST: Update state of alarm."""

    def __init__(self):
        super().__init__()
        self.state = "OFF"

    async def render_post(self, request):
        self.state = request.payload
        print('Update alarm state: %s' % self.state)
        return aiocoap.Message(code=aiocoap.CHANGED, payload=self.state)
    async def render_get(self, request):
        return aiocoap.Message(payload=self.state)

def main():
    # Resource tree creation
    root = resource.Site()
    root.add_resource(['alarm'], AlarmResource())

    asyncio.Task(aiocoap.Context.create_server_context(root, bind=('localhost', 5683)))

    asyncio.get_event_loop().run_forever()

if __name__ == "__main__":
    main()
