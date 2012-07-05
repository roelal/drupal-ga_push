(function ($) {

  Drupal.behaviors.ga_push_browser = {
    attach: function (context, settings) {

      ga_push_browser = Drupal.settings.ga_push_browser;

      /* TODO: preparar para que solo salte una vez */

      $.each(ga_push_browser, function(index, value) {

        $(value['selector']).bind(value['bind'], function() {

          if (typeof(_gaq) == 'object') {
            if (typeof(console) == 'object' && typeof(console.log) == 'function') {
              console.log('push (' + value['push'][0] + ' | ' + value['push'][1] + ' | ' + value['push'][2] + ' | ' + value['push'][3] + ')');
            }
            _gaq.push(['_trackEvent', value['push'][0], value['push'][1], value['push'][2] , value['push'][3]]);
          }

        });

      });


    } //Behaviors
  }

})(jQuery);
