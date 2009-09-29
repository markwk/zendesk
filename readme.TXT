README
======
The zendesk module allows you to integrate your drupal site with the zendesk 
customer support system (http://www.zendesk.com)

Zendesk allows external authentication meaning that your Drupal site can serve
as authentication service. This way customers have a seamless experience without 
having to log in in both the drupal site and the zendesk support system.

Installation is easy:
- install the module
- configure your zendesk account (go to 'account - Integration')
  * insert the remote authentication url: http://yoursite.com/services/zendesk
  * optionally you can insert your logout url: http://yoursite.com/logout    
- go to admin/settings/zendesk and fill in the url of your zendesk support page
together with the secret key

Tom